#pragma once
#include <iostream>
using namespace std;
#define WINDOW_WIDTH 1280	//画面の幅
#define WINDOW_HEIGHT 960	//画面の高さ
#define MASSSIZE 64 //マス一個のサイズ

#define DEBUG

//DxLibの表示系関数のxy座標は全て引数がintの為doubleで指定すると警告がでるので例外処理
#pragma warning(disable: 4244)

//vectorのsize()関数を使ったfor文において
//size()の戻り値がunsigned intになりsigned int型と比較すると警告が出るので例外処理
#pragma warning(disable: 4018)

//strcpyを使用すると非推奨としてエラーが出るので例外処理
#pragma warning(disable : 4996)
//職業判定ようのenum
typedef enum {
	eTank,
	eCaster,
	eRanger,
	eFighter
}eRole;
//eRole role;

//Load.cpp内でのクラス識別用
typedef enum {
	eChara,
	eEnemy,
	eFairy
}eClass;




