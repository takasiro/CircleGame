#include "Unit.h"
#include "Fairy.h"
Unit::Unit() {
	Initialize();
}
Unit::Unit(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv) {
	Initialize(_name, _role, _hp, _str, _def, _int, _mnd, _dex, _agi, _move, _exp, _lv);
}
int Unit::Initialize(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv) {
	mRole = _role;
	strcpy(mName, _name);
	mHp = _hp;
	mMaXHp = mHp;
	mStr = _str;
	mDef = _def;
	mInt = _int;
	mMnd = _mnd;
	mDex = _dex;
	mAgi = _agi;
	mMove = _move;
	mExp = _exp;
	mLv = _lv;
	mStayFlg = false;
	return 0;
}

int Unit::SetGrowth(float _hp, float _str, float _def, float _int, float _mnd, float _dex, float _agi) {
	mGrowthHp = _hp;
	mGrowthStr = _str;
	mGrowthDef = _def;
	mGrowthInt = _int;
	mGrowthMnd = _mnd;
	mGrowthDex = _dex;
	mGrowthAgi = _agi;
	return 0;
}

Unit::~Unit() {
	;
}
int Unit::Initialize() {
	return 0;
}
int Unit::Update() {
	return 0;
}

int Unit::Draw() {
	return 0;
}

int Unit::Close() {
	return 0;
}

int Unit::StatusUp(int _lv) {
	return 0;
}

int Unit::LastStatus() {
	return 0;
}
int Unit::Move(int _x, int _y) {
	return 0;
}




