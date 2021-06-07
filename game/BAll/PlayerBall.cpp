//#include "ºê.h"
//
//PlayerBall::PlayerBall()
//{
//	this->x = WinWidth / 2;
//	this->y = WinHigh / 2;
//	this->r = 20;
//	this->color = GREEN;
//}
//
//void PlayerBall::ChangePlayer(int x, int y, unsigned r, COLORREF color)
//{
//	this->x = x;
//	this->y = y;
//	this->r = r;
//	this->color = color;
//}
//
//void PlayerBall::DrawPlayer() {
//	setfillcolor(color);
//	setlinecolor(RGB(rand() % 256, rand() % 256, rand() % 256));
//	fillcircle(x, y, r);
//}
//
//void PlayerBall::PlayerMove()
//{
//	if (GetAsyncKeyState(VK_UP))
//	{
//		this->y -= 2;
//	}
//	if (GetAsyncKeyState(VK_DOWN))
//	{
//		this->y += 2;
//	}
//	if (GetAsyncKeyState(VK_LEFT))
//	{
//		this->x -= 2;
//	}
//	if (GetAsyncKeyState(VK_RIGHT))
//	{
//		this->x += 2;
//	}
//}