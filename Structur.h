#pragma once

typedef struct Drop
{
	bool state;
	int color;

	struct Drop* Last;
	struct Drop* Next;
}Drop;

typedef struct ReLine
{
	struct Drop* Drop;

	struct ReLine* Last;
	struct ReLine* Next;
}ReLine;

typedef struct DissPlay
{
	int GetSetSize;

	int WindowWidth;
	int WindowHeight;

	int WidthNumber;
	int HeightNumber;

	bool click;

	//×óÊÖ¼ü
	bool K_S;
	bool K_D;
	bool K_F;

	//ÓÒÊÖ¼ü
	bool K_J;
	bool K_K;
	bool K_L;

	struct ReLine* DissArr;
	struct ReLine* GetSetArr;

}DP;