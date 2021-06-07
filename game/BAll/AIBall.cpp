//#include "ºê.h"
//#include <list>
//#include <math.h>
//#include <vector>
//using namespace std;
//
//vector<BALL> Ai;
//vector< vector<BALL>::iterator> Tmpy;
//
//AIBall::AIBall()
//{
//	Num = 0;
//}
//
//void AIBall::CreateAI()
//{
//	if (Num < 99)
//	{
//		for (; Num < 99; Num++)
//		{
//			BALL ball;
//			ball.x = rand() % WinWidth;
//			ball.y = rand() % WinHigh;
//			ball.r = rand() % 20 + 10;
//			ball.color = RGB(rand() % 256, rand() % 256, rand() % 256);
//			Ai.push_back(ball);
//		}
//	}
//}
//
//void AIBall::DrawAI()
//{
//	for (list<BALL>::iterator it = Ai.begin(); it != Ai.end(); it++)
//	{
//		setlinecolor(LIGHTGRAY);
//		setfillcolor(it->color);
//		fillcircle(it->x, it->y, it->r);
//	}
//}
//
//void AIBall::JudgeBall()
//{
//	for (vector<BALL>::iterator it1 = Ai.begin(); it1 != Ai.end(); it1++)
//	{
//		for (vector<BALL>::iterator it2 = Ai.begin(); it2 != Ai.end(); it2++)
//		{
//			int Cross = sqrt(pow((it1->x + it2->x),2) + pow((it1->y + it2->y),2));
//			if (Cross < (it1->r + it2->r) / 2)
//			{
//				if (it1->r > it2->r)
//				{
//					Tmpy.push_back(it2);
//					Num--;
//				}
//				else
//				{
//					Tmpy.push_back(it1);
//					Num--;
//				}
//			}
//		}
//	}
//	for (vector< vector<BALL>::iterator>::iterator it = Tmpy.begin(); it != Tmpy.end(); it++)
//	{
//		Ai.erase(*it);
//	}
//}