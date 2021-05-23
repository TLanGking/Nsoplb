#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

void initWindow();
void showMSG();

int With = 860;
int High = 640;
int ScopeX = 10 + 30 * ((With - 20) / 30);
int ScopeY = 10 + 30 * ((High - 20) / 30);
//键码值枚举
enum KeyCode
{
	up = 72,
	down = 80,
	left = 75,
	right = 77
};
class myXY
{
public:
	myXY()
	{
		x = 0;
		y = 0;
	}
	int x;
	int y;

};
//对象模块
//蛇
//蛇的属性：蛇的节数，蛇的分数，蛇的方向
class SNAKE
{
public:
	SNAKE();
	void DrawSnake();
	void MoveSnake();
	void UserCtrl();
	bool SnakeDie();
	int Number;
	myXY S_xy[100];
	int Score;	
	KeyCode Direction;
}Snake;

SNAKE::SNAKE()
{
	Score = 0;
	Number = 3;
	Direction = right;

	S_xy[0].x = 60 + 10;
	S_xy[0].y = 10;

	S_xy[1].x = 30 + 10;
	S_xy[1].y = 10;
	
	S_xy[2].x = 10;
	S_xy[2].y = 10;
}

void SNAKE::DrawSnake()
{
	initWindow();
	setlinecolor(BLACK);	
	setfillcolor(LIGHTBLUE);
	for (int i = 0; i < Number; i++)
	{
		fillrectangle(S_xy[i].x, S_xy[i].y, S_xy[i].x + 30, S_xy[i].y + 30);
	}
}
void SNAKE::MoveSnake()
{
	for (int i = Number - 1; i > 0; i--)
	{
		S_xy[i].x = S_xy[i - 1].x;
		S_xy[i].y = S_xy[i - 1].y;
	}
	switch (Direction)
	{
	case up:
		S_xy[0].y -= 30;
		break;
	case down:
		S_xy[0].y += 30;
		break;
	case left:
		S_xy[0].x -= 30;
		break;
	case right:
		S_xy[0].x += 30;
		break;
	default:
		break;
	}
}
void SNAKE::UserCtrl()
{
	char key = _getch();
	switch (key)
	{
	case up:
		if (Direction != down)
		{
			Direction = up;
		}	
		break;
	case down:
		if (Direction != up)
		{
			Direction = down;
		}
		break;
	case left:
		if (Direction != right)
		{
			Direction = left;
		}
		break;
	case right:
		if (Direction != left)
		{
			Direction = right;
		}
		break;
	default:
		break;
	}
}

bool SNAKE::SnakeDie()
{
	if (S_xy[0].x < 10 || S_xy[0].x >= ScopeX || S_xy[0].y < 10 || S_xy[0].y >= ScopeY)
	{
		return true;
	}
	for (int i = 1; i < Number; i++)
	{
		if (S_xy[0].x == S_xy[i].x && S_xy[0].y == S_xy[i].y)
		{		
			return true;
		}
	}
	return false;
}
//食物
class FOOD:private myXY
{
public:
	void initFood();
	void DrawFood();
	void FoodDie();
	bool Flive;
	myXY F_xy;
}Food;

void FOOD::initFood()
{
	srand(unsigned int(time(NULL)));
	while (true)
	{
		F_xy.x = rand() % (ScopeX - 30) / 30 * 30 + 10;
		F_xy.y = rand() % (ScopeY - 30) / 30 * 30 + 10;
		int i = 0;
		for (; i < Snake.Number; i++)
		{
			if (F_xy.x == Snake.S_xy[i].x && F_xy.y == Snake.S_xy[i].y)
			{
				continue;
			}
		}
		if (i == Snake.Number)
		{
			break;
		}
	}
	Flive = true;
}

void FOOD::FoodDie()
{
	if (Snake.S_xy[0].x == F_xy.x && Snake.S_xy[0].y == F_xy.y)
	{
		Flive = false;
		Snake.Score += 10;
		Snake.Number++;
		Snake.S_xy[Snake.Number - 1].x = Snake.S_xy[Snake.Number - 2].x;
		Snake.S_xy[Snake.Number - 1].y = Snake.S_xy[Snake.Number - 2].y;
	}
}



void FOOD::DrawFood()
{
	setfillcolor(YELLOW);
	solidcircle(F_xy.x + 15,F_xy.y + 15,15);
}


int main()
{
	initgraph(With, High);
	initWindow();
	Food.Flive = false;
	while (true)
	{
		if (Food.Flive == false)
		{
			Food.initFood();
		}
		cleardevice();
		Snake.DrawSnake();
		Food.DrawFood();
		while (_kbhit())
		{
			Snake.UserCtrl();
		}
		Snake.MoveSnake();
		Food.FoodDie();
		if (Snake.SnakeDie())
		{
			showMSG();
			settextcolor(LIGHTGREEN);
			settextstyle(50, 0, TEXT("楷体"));
			outtextxy(ScopeX / 2 - 50 * 2, ScopeY / 2  - 150, TEXT("你死了！"));
			while (!_kbhit());
			return 0;
		}
		Sleep(300);
	}
	closegraph();
	return 0;
}

void initWindow()
{
	setbkcolor(WHITE);
	cleardevice();
	setfillcolor(GREEN);
	solidrectangle(0, 0, With, High);
	clearrectangle(10, 10, ScopeX, ScopeY);
}

void showMSG()
{
	setfillcolor(LIGHTGRAY);		
	setbkmode(TRANSPARENT);
	solidrectangle(ScopeX / 2 - 250, ScopeY / 2 - 200, ScopeX / 2 + 250, ScopeY / 2 + 200);
	settextcolor(RED);
	settextstyle(30, 0, TEXT("宋体"));
	outtextxy(ScopeX / 2 - 30 * 2, ScopeY / 2, TEXT("得分："));
	outtextxy(ScopeX / 2 + 30, ScopeY / 2, (char)Snake.Score);
	settextcolor(WHITE);
	settextstyle(40, 0, TEXT("宋体"));
	outtextxy(ScopeX / 2 - 40 * 3, ScopeY / 2 + 150, TEXT("按任意键继续"));
}