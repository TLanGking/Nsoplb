#pragma once
#include <graphics.h>
class Ball
{
public:
	//��������
	int x;
	int y;
	int r;
	COLORREF color;
	//������Ϊ
	void InitBall(int a,int b,int c,COLORREF d);
};

