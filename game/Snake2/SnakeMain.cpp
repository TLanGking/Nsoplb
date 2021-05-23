#include <graphics.h>
#include <vector>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#define DOWN 80
#define UP 72
#define LEFT 75
#define RIGHT 77
using namespace std;

//坐标类
class Coordinate
{
public:
	Coordinate(int x, int y)
	{
		this->C_x = x;
		this->C_y = y;
	}
	int C_x;
	int C_y;
};

//关于蛇的类和数据
vector<Coordinate> mySnake;
class Snake
{
public:
	Snake();
	~Snake();
	void DrawSnake();
	void SnakeMove();
	void UserKey();
	bool IfDie();
	void SnakeGrow();
private:
	unsigned int Direction;
	unsigned int Score;
};

Snake::Snake()
{
	Direction = RIGHT;
	Score = 0;

	Coordinate c1(25 * 2, 0);
	Coordinate c2(25 * 1, 0);
	Coordinate c3(0, 0);
	mySnake.push_back(c1);
	mySnake.push_back(c2);
	mySnake.push_back(c3);
}

void Snake::DrawSnake()
{
	setfillcolor(YELLOW);
	setlinecolor(RED);
	for (vector<Coordinate>::iterator it = mySnake.begin(); it != mySnake.end(); it++)
	{
		fillrectangle(it->C_x, it->C_y, it->C_x + 25, it->C_y + 25);
	}	
}

void Snake::SnakeMove()
{
	for (vector<Coordinate>::iterator it = mySnake.end() - 1; it != mySnake.begin(); it--)
	{
		it->C_x = (it - 1)->C_x;
		it->C_y = (it - 1)->C_y;
	}
	switch (Direction)
	{
	case UP:
		mySnake.front().C_y -= 25;
		break;
	case DOWN:
		mySnake.front().C_y += 25;
		break;
	case LEFT:
		mySnake.front().C_x -= 25;
		break;
	case RIGHT:
		mySnake.front().C_x += 25;
		break;
	default:
		break;
	}	
}

void Snake::UserKey()
{
	int value = (int)getch();
	switch (value)
	{
	case UP:
		if (Direction != DOWN)
		{
			Direction = UP;
		}
		break;
	case DOWN:
		if (Direction != UP)
		{
			Direction = DOWN;
		}
		break;
	case LEFT:
		if (Direction != RIGHT)
		{
			Direction = LEFT;
		}
		break;
	case RIGHT:
		if (Direction != LEFT)
		{
			Direction = RIGHT;
		}
		break;
	default:
		break;
	}
}

bool Snake::IfDie()
{
	for (vector<Coordinate>::iterator it = mySnake.begin(); it != mySnake.end(); it++)
	{
		if (it->C_x < 0 || it->C_x >= 625 || it->C_y < 0 || it->C_y >= 475)
		{
			system("pause");
			return false;
		}
	}
	for (vector<Coordinate>::iterator it = mySnake.begin() + 1; it != mySnake.end(); it++)
	{
		if (it->C_x == mySnake.front().C_x && it->C_y == mySnake.front().C_y)
		{
			system("pause");
			return false;
		}
	}
	return true;
}

void Snake::SnakeGrow()
{
	this->Score += 10;
}

Snake::~Snake()
{
	mySnake.clear();
}
//食物
class Food
{
public:
	Food();
	Coordinate InitFood();
	void DrawFood(Coordinate c);
	bool Exist();
	void FoodGone(Coordinate c);
private:
	bool IfExist;
};

Food::Food()
{
	IfExist = false;
}

Coordinate Food::InitFood()
{
	int x = 0, y = 0;
	while (true)
	{
		x = rand() % 25 * 25;
		y = rand() % 19 * 25;
		vector<Coordinate>::iterator it = mySnake.begin();
		for (; it != mySnake.end(); it++)
		{
			if (it->C_x == x && it->C_y == y)
			{
				break;
			}
		}
		if (it == mySnake.end())
		{
			IfExist = 1;
			return Coordinate(x, y);
		}
	}
}

void Food::DrawFood(Coordinate c)
{
	setfillcolor(GREEN);
	setlinecolor(YELLOW);
	fillrectangle(c.C_x, c.C_y, c.C_x + 25, c.C_y + 25);
}

bool Food::Exist()
{
	return IfExist;
}

void Food::FoodGone(Coordinate c)
{
	if (mySnake.front().C_x == c.C_x && mySnake.front().C_y == c.C_y)
	{
		this->IfExist = false;		
	}
}
//交互框架
class Interaction
{
public:
	Interaction();
	~Interaction();
	void initGame();
	void GameProcess();
private:
	unsigned int WinWidth;
	unsigned int WinHigh;

};

Interaction::Interaction()
{
	WinWidth = 640;
	WinHigh = 480;

	initgraph(WinWidth, WinHigh);
}

void Interaction::initGame()
{
	setbkcolor(WHITE);
	cleardevice();
}

void Interaction::GameProcess()
{
	Snake s;
	Food f;
	Coordinate c(0,0);
	Coordinate s_c(0, 0);
	s.DrawSnake();
	int i = 0;
	do
	{
		s_c = Coordinate(mySnake.back().C_x, mySnake.back().C_y);
		s.SnakeMove();
		cleardevice();
		if (f.Exist())
		{
			f.FoodGone(c);
		}
		else
		{
			c = f.InitFood();	
			if (i)
			{
				s.SnakeGrow();
				mySnake.push_back(s_c);
			}
		}
		s.DrawSnake();	
		f.DrawFood(c);
		Sleep(150);		
		while (kbhit())
		{
			s.UserKey();
		}
		i++;
	} while (s.IfDie());

}

Interaction::~Interaction()
{
	closegraph();
}

int main()
{
	srand(unsigned int(time(NULL)));
	Interaction itt;
	itt.initGame();
	itt.GameProcess();
	return 0;
}