#pragma once
#include <graphics.h>
class Ball
{
public:
	//球类属性
	int x;
	int y;
	int r;
	COLORREF color;
	//球类行为
	void InitBall(int a,int b,int c,COLORREF d);
};

