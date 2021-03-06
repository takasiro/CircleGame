#include "Effect.h"



Effect::Effect()
{
	SetOnActive(false);
}


Effect::~Effect()
{
}

int Effect::Initialize() {
	if (mAllNum != 0) SetGrHandleCount(mAllNum);
	SetGrHandles(new int[GetGrHandleCount()]);
	LoadDivGraph(mFileName, mAllNum, mXNum, mYNum, mXSize, mYSize, GetGrHandles());
	mWidth = mXSize;
	mHeight = mYSize;
	return 0;
}

int Effect::Update() {
	if (GetOnActive() != true)return 1;
	mEffectCounter++;
	if (mEffectCounter / 2 == GetGrHandleCount()) {
		SetOnActive(false);
		mEffectCounter = -1;
	}
	return 0;
}

int Effect::Draw() {
	int tmpg = GetGrHandles()[mEffectCounter];
	int tmp = DrawGraph(GetPosX(), GetPosY(), GetGrHandles()[mEffectCounter/2],true);
	return 0;
}


int Effect::Close() {
	delete[] GetGrHandles();
	return 0;
}

int Effect::SetAll(char* _Name, int _AllNum, int _XNum, int _YNum, int _XSize, int _YSize, char* _FileName) {
	strcpy(mName, _Name);
	mAllNum = _AllNum;
	mXNum = _XNum;
	mYNum = _YNum;
	mXSize = _XSize;
	mYSize = _YSize;
	strcpy(mFileName, _FileName);
	return 0;
}