#define _CRT_SECURE_NO_WARNINGS

#include"head.h"

int ReNumber = 10;

DP diss{ 0 };

void Choick()
{
	diss.K_D = false;
	diss.K_F = false;
	diss.K_J = false;
	diss.K_K = false;

	if (GetAsyncKeyState('D'))
	{
		diss.K_D = true;
		diss.click = true;
	}
	if (GetAsyncKeyState('F'))
	{
		diss.K_F = true;
		diss.click = true;
	}
	if (GetAsyncKeyState('J'))
	{
		diss.K_J = true;
		diss.click = true;
	}
	if (GetAsyncKeyState('K'))
	{
		diss.K_K = true;
		diss.click = true;
	}
}

void InitRePlay()
{
	diss.DissArr = GetRepateLine(ReNumber);
	FILE* pLevel = fopen("./Level/1.txt", "rt");
	assert(pLevel);
	fscanf(pLevel, "%d\n", &diss.GetSetSize);
	diss.GetSetArr = GetRepateLine(diss.GetSetSize);
	ReLine* TmpReLine = diss.GetSetArr;
	for (int i = 0; i < diss.GetSetSize; i++)
	{
		Drop* TmpDrop = TmpReLine->Drop;
		for (int j = 0; j < 4; j++)
		{
			int Buffer = 0;
			fscanf(pLevel, "%d", &Buffer);
			TmpDrop->state = Buffer;
			TmpDrop = TmpDrop->Next;
		}
		fscanf(pLevel, "\n");
		TmpReLine = TmpReLine->Next;
	}
	fclose(pLevel);
	pLevel = NULL;
	//将预备区复制到显示区
	ReLine* TmpDissReLine = diss.DissArr;
	TmpReLine = diss.GetSetArr;
	for (int i = 0; i < ReNumber; i++)
	{
		Drop* TmpDrop = TmpReLine->Drop;
		Drop* TmpDissDrop = TmpDissReLine->Drop;
		for (int j = 0; j < 4; j++)
		{
			TmpDissDrop->state = TmpDrop->state;
			if (TmpDissDrop->state)
			{
				TmpDissDrop->color = RGB(244, 137, 83);
			}
			TmpDrop = TmpDrop->Next;
			TmpDissDrop = TmpDissDrop->Next;
		}

		TmpReLine = TmpReLine->Last;
		TmpDissReLine = TmpDissReLine->Next;
	}

	diss.WidthNumber = 4;
	diss.HeightNumber = ReNumber;
	diss.WindowWidth = 400;
	diss.WindowHeight = 1000;

}

void GetSet_To_Diss()
{
	//往后走之后复制
	diss.DissArr = diss.DissArr->Last;
	diss.GetSetArr = diss.GetSetArr->Next;

	Drop* TmpDissDrop = diss.DissArr->Drop;
	Drop* TmpDrop = diss.GetSetArr->Drop;
	for (int i = 0; i < 4; i++)
	{
		TmpDissDrop->state = TmpDrop->state;
		if (TmpDissDrop->state)
		{
			TmpDissDrop->color = RGB(244, 137, 83);
		}
		else
		{
			TmpDissDrop->color = NULL;
		}
		TmpDrop = TmpDrop->Next;
		TmpDissDrop = TmpDissDrop->Next;
	}
}

int Rehabilitation()
{
	InitRePlay();

	bool L = false;

	dissPlay(&diss);
	BeginBatchDraw();

	while (true)
	{
		//点击一次往后一次
		Choick();
		Sleep(10);

		if (diss.click)
		{
			diss.click = false;
			L = true;
		}
		else if (L && !diss.click)
		{
			GetSet_To_Diss();
			L = false;
		}

		dissPlay(&diss);
		FlushBatchDraw();
	}
	EndBatchDraw();
	CloseRepate(diss.DissArr);
	CloseRepate(diss.GetSetArr);
	diss.DissArr = diss.GetSetArr = nullptr;
	diss.GetSetSize = NULL;
	return 0;
}