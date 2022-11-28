#define _CRT_SECURE_NO_WARNINGS

#include"Head.h"

int WindowWidth = 400;
int WindowHeight = 1000;

void initGame()
{
	initgraph(WindowWidth, WindowHeight);
	setbkcolor(RGB(255, 249, 239));
	settextcolor(RGB(112, 112, 112));
	setbkmode(TRANSPARENT);
	//setlinestyle(PS_NULL);
	setlinecolor(RGB(0, 0, 0));
	cleardevice();

}

int main()
{
	initGame();

	rectangle(100, 100, 300, 900);

	//数据结构采用循环链表
	system("pause");

	Rehabilitation();
	return 0;
}