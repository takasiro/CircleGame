#pragma once
#include<iostream>
using namespace std;

#include<string>
#include<vector>
#include"BaseObj.h"
#include"BaseTask.h"
#include"Mouse.h"
#include"Mass.h"
#include"UnitMgr.h"
#include"Unit.h"
#include"fairy.h"
#include"Enemy.h"

class UI :public BaseTask {
private:
	typedef struct {
		char* _name; 
		eRole _role; 
		int _hp;
		int _str; 
		int _def;
		int _int;
		int _mnd;
		int _dex; 
		int _agi; 
		int _exp;
		int _lv;
	}sStatus;

	int num;
	vector<Chara*> charaStatus;

public:
	UI() { Initialize(); };
	virtual ~UI() {};

	int DrawStatus();

	int Initialize() { return 0; }	//初期化処理
	int Update();	//計算処理
	int Draw();		//描画処理
	int Close() { return 0; }		//終了処理
};
