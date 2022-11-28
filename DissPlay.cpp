#define _CRT_SECURE_NO_WARNINGS

#include"Head.h"

void dissPlay(DP* diss)
{
	cleardevice();

	TCHAR Buffer[1024] = L"";
	
	int Ydown = diss->WindowHeight - diss->WindowHeight / 20 * 3;
	setfillcolor(0xEEEEEE);
	fillrectangle(0, Ydown, diss->WindowWidth, diss->WindowHeight);
	
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = (diss->WindowHeight - Ydown);
	f.lfWidth = (diss->WindowHeight < diss->WindowWidth ? diss->WindowHeight : diss->WindowWidth) / 5;
	_tcscpy(f.lfFaceName, _T("宋体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);

	int x, y, w, h;
	x = y = w = h = 0;

	w = diss->WindowWidth / diss->WidthNumber;
	h = Ydown / diss->HeightNumber;

	//方块显示
	ReLine* TmpReLine = diss->DissArr;
	for (int i = 0; i < diss->HeightNumber; i++)
	{
		x = 0;
		Drop* TmpDrop = TmpReLine->Drop;
		for (int j = 0; j < diss->WidthNumber; j++)
		{
			if (TmpDrop->state)
			{
				setfillcolor(TmpDrop->color);
				fillrectangle(x, y, x + w, y + h);
			}
			else
			{
				rectangle(x, y, x + w, y + h);
			}
			x += w;
			TmpDrop = TmpDrop->Next;
		}
		y += h;
		TmpReLine = TmpReLine->Next;
	}


	//显示键控
	w = diss->WindowWidth / 4;
	setfillcolor(RGB(230, 197, 158));
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			if (diss->K_D)
			{
				fillrectangle(i * w, Ydown, (i + 1) * w, diss->WindowHeight);
			}
			else
			{
				rectangle(i * w, Ydown, (i + 1) * w, diss->WindowHeight);
			}
			break;
		case 1:
			if (diss->K_F)
			{
				fillrectangle(i * w, Ydown, (i + 1) * w, diss->WindowHeight);
			}
			else
			{
				rectangle(i * w, Ydown, (i + 1) * w, diss->WindowHeight);
			}
			break;
		case 2:
			if (diss->K_J)
			{
				fillrectangle(i * w, Ydown, (i + 1) * w, diss->WindowHeight);
			}
			else
			{
				rectangle(i * w, Ydown, (i + 1) * w, diss->WindowHeight);
			}
			break;
		case 3:
			if (diss->K_K)
			{
				fillrectangle(i * w, Ydown, (i + 1) * w, diss->WindowHeight);
			}
			else
			{
				rectangle(i * w, Ydown, (i + 1) * w, diss->WindowHeight);
			}
			break;
		default:
			break;
		}
	}

	
	//显示文字dfjk
	{
		strcpy((char*)Buffer, (char*)L"D");
		x = diss->WindowWidth / 4 / 2 - textwidth(Buffer) / 2;
		y = Ydown + (diss->WindowHeight - Ydown) / 2 - textheight(Buffer) / 2;
		outtextxy(x, y, Buffer);

		strcpy((char*)Buffer, (char*)L"F");
		x += w;
		y = Ydown + (diss->WindowHeight - Ydown) / 2 - textheight(Buffer) / 2;
		outtextxy(x, y, Buffer);

		strcpy((char*)Buffer, (char*)L"J");
		x += w;
		y = Ydown + (diss->WindowHeight - Ydown) / 2 - textheight(Buffer) / 2;
		outtextxy(x, y, Buffer);

		strcpy((char*)Buffer, (char*)L"K");
		x += w;
		y = Ydown + (diss->WindowHeight - Ydown) / 2 - textheight(Buffer) / 2;
		outtextxy(x, y, Buffer);
	}
}