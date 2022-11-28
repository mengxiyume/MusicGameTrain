#define _CRT_SECURE_NO_WARNINGS

#include"Head.h"

#define DropNumber 4
#define ReLineNumber 10

Drop* GetDrop(Drop* Last)
{
	Drop* TmpDrop = (Drop*)calloc(1, sizeof(Drop));
	assert(TmpDrop);
	if (Last)
	{
		Last->Next = TmpDrop;
		TmpDrop->Last = Last;
	}
	return TmpDrop;

}

ReLine* GetLine(ReLine* Last)
{
	ReLine* TmpReLine = (ReLine*)calloc(1, sizeof(ReLine));
	assert(TmpReLine);

	Drop* TmpDrop = nullptr;

	for (int i = 0; i < DropNumber; i++)
	{
		TmpDrop = GetDrop(TmpDrop);
		if (!i)
		{
			TmpReLine->Drop = TmpDrop;
		}
	}

	if (Last)
	{
		Last->Next = TmpReLine;
		TmpReLine->Last = Last;
	}
	return TmpReLine;
}

ReLine* GetRepateLine(size_t ReNumber)
{
	assert(ReNumber);
	ReLine* TmpLine = nullptr;
	ReLine* Begin = nullptr;
	for (int i = 0; i < ReNumber; i++)
	{
		TmpLine = GetLine(TmpLine);
		if (!i)
		{
			Begin = TmpLine;
		}
	}
	TmpLine->Next = Begin;
	Begin->Last = TmpLine;
	return Begin;
}

void CloseDrop(Drop* dest)
{
	assert(dest);
	free(dest);
}

void CloseLine(ReLine* dest)
{
	assert(dest && dest->Drop);
	Drop* TmpDrop = nullptr;
	Drop* Next = dest->Drop;
	while (Next)
	{
		TmpDrop = Next;
		Next = Next->Next;
		TmpDrop->Last = nullptr;
		TmpDrop->Next = nullptr;
		free(TmpDrop);
		TmpDrop = nullptr;
	}
	dest->Drop = nullptr;
	
}

void CloseRepate(ReLine* dest)
{
	assert(dest && dest->Next && dest->Last);

	//断开链接
	dest->Last->Next = NULL;
	dest->Last = NULL;
	
	//普通关闭
	CloseLine(dest);
}