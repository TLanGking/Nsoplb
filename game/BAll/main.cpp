#include "宏.h"

#include "Ball.h"
#include <vector>
using namespace std;
vector<Ball> GameBall;

void DrawGame();		//渲染游戏画面
void PlayerMove();		//玩家控制移动
Ball GenerateBall();	//生成人机Ball
void JudgeDie();		//判断Ball死亡

int main()
{
	//初始化界面
	initgraph(WinWidth, WinHigh);
	BeginBatchDraw();		//开始缓冲（双缓冲）
	setbkcolor(WHITE);
	srand((unsigned)time(NULL));			//随机种子
	//初始化数据
	Ball player;
	player.InitBall(WinWidth / 2, WinHigh / 2, 20, BLUE);
	GameBall.push_back(player);
	//进入游戏循环
	do
	{		
		cleardevice();			//清屏
		if (GameBall.size() < 100)
		{
			GameBall.push_back(GenerateBall());
		}	
		DrawGame();
		PlayerMove();
		JudgeDie();
		/*AI.CreateAI();	
		AI.JudgeBall();
		AI.DrawAI();
		player.DrawPlayer();*/
		FlushBatchDraw();		//刷新（双缓冲）
	} while (true);
	closegraph();
	return 0;
}

void DrawGame()
{
	for (vector<Ball>::iterator it = GameBall.begin() + 1; it != GameBall.end(); it++)
	{	
		setlinecolor(LIGHTCYAN);
		setfillcolor(it->color);
		fillcircle(it->x, it->y, it->r);
	}
	setlinecolor(RGB(rand() % 256, rand() % 256, rand() % 256));
	setfillcolor(GameBall.begin()->color);
	fillcircle(GameBall.begin()->x, GameBall.begin()->y, GameBall.begin()->r);

}

void PlayerMove()
{
	if (GetAsyncKeyState(VK_UP))
	{
		GameBall.begin()->y -= 2;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		GameBall.begin()->y += 2;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		GameBall.begin()->x -= 2;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		GameBall.begin()->x += 2;
	}
}

Ball GenerateBall()
{
	int x, y;
	vector<Ball>::iterator it;
	while (true)
	{
		x = rand() % WinWidth;
		y = rand() % WinHigh;
		for (it = GameBall.begin(); it != GameBall.end(); it++)
		{
			if (x == it->x && y == it->y)
			{
				break;
			}
		}
		if (it == GameBall.end())
		{
			Ball tmp;
			tmp.InitBall(x, y, rand() % 20 + 10, RGB(rand() % 256, rand() % 256, rand() % 256));
			return tmp;
		}
	}
}

void JudgeDie()
{
	for (vector<Ball>::iterator it = GameBall.begin() + 1; it != GameBall.end(); it++)
	{
		double distance = sqrt((GameBall.begin()->x + it->x) * (GameBall.begin()->x + it->x)
			+ (GameBall.begin()->y + it->y) * (GameBall.begin()->y + it->y));
		int minR = GameBall.begin()->r > it->r ? it->r : GameBall.begin()->r;
		if (distance < minR)
		{
			if (GameBall.begin()->r > it->r)
			{
				GameBall.begin()->r += it->r;
				vector<Ball> value(GameBall.begin(), it - 1);
				value.insert(it, it + 1, GameBall.end());
				GameBall = value;
			}
			else if (GameBall.begin()->r < it->r)
			{
				it->r += GameBall.begin()->r;
			}
		}
	}
}