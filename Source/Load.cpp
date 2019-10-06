#include<DxLib.h>
#include"Load.h"
int Load::Initialize() {
	mHp = 0;		//体力
	mStr = 0;		//力(物理用)
	mDef = 0;		//防御(物理用)
	mIntelli = 0;		//魔力(魔法用)
	mMnd = 0;		//魔防(魔法用)
	mGrowthDex = 0;		//	命中
	mAgi = 0;		//回避
	mMove = 0;	//移動力

	mRangeMin = 0;
	mRangeMax = 0;

	mGrowthHp = 0;
	mGrowthStr = 0;
	mGrowthDef = 0;
	mGrowthIntelli = 0;
	mGrowthMnd = 0;
	mGrowthDex = 0;
	mGrowthAgi = 0;
	return 0;
}

int Load::LoadFile(int _fileHandle, char* _data) {
	DrawFormatString(100, 250, GetColor(255, 255, 255), "Load");
	for (int i = 0; i < 64; i++) {
		DrawFormatString(100, (i + 1) * 20 + 250, GetColor(255, 255, 255), "Load%d", i);
		_data[i] = FileRead_getc(_fileHandle);  //ファイル読み込み

		if (_data[i] == '/') { //スラッシュがあれば 
			if (i > 0 && _data[i - 1] == '/') {
				while (FileRead_getc(_fileHandle) != '\n');//改行までループ
				i = -1;//カウンタを最初に戻して
				continue;
			}
		}

		if (_data[i] == EOF)return 0;  //ファイル終端ならそこで終わる

		if (_data[i] == ',' || _data[i] == '-' || _data[i] == '\n') {//カンマか改行の場合
			_data[i] = '\0';  //そこまでを文字列とする
			break;
		}
	}
}

/******************************************************
型:int
引数:const char* _filePath…読み込むファイルのパス
　　 vector<Mass>& _mass…マップの地形情報を格納する　
*******************************************************/
int Load::LoadData(const char* _filePath, vector<Mass>& _mass) {

	int stageHandle = FileRead_open(_filePath);  //ファイルオープン

	char input[256];

	if (stageHandle == NULL)return -1;

	while (FileRead_eof(stageHandle) == 0) {  //ファイルの終端まで
		LoadFile(stageHandle, input);  //データ読み込み	
		_mass.emplace_back(Mass(0, atoi(input), 0));  //Mass配列に代入		
	}

	FileRead_close(stageHandle);

	return 0;
}

/**************************************************************************
型:int
引数:const char* _baseFilePath…読み込むファイルのパス
	 const char* _growthFilePath…読み込むファイルのパス
　　 vector<Mass>& _unit…基礎ステータスと成長後ステータスを格納する
***************************************************************************/
//int LoadData(const char* _baseFilePath, const char* _growthFilePath){
int Load::LoadData(const char* _baseFilePath, const char* _growthFilePath, vector<Unit>& _unit) {
	//ファイルオープン
	mBaseHandle = FileRead_open(_baseFilePath);
	mGrowthHandle = FileRead_open(_growthFilePath);

	int n = 0;
	int nn = 0;

	if (mBaseHandle == NULL)return -1;
	if (mGrowthHandle == NULL)return -1;

	while (FileRead_eof(mBaseHandle) == 0) {
		while (FileRead_eof(mBaseHandle) == 0) {  //ファイルの終端まで

			if (strstr(_baseFilePath, "Fairy") && FileRead_eof(mBaseHandle) == 0) {
				LoadWeapon(mBaseHandle, mGrowthHandle, _unit);
			}
			else if (FileRead_eof(mBaseHandle) == 0) {
				LoadChara(mBaseHandle, mGrowthHandle, _unit);
			}

			/*
			最新版更新時の処理　まだ最新版が上がってないのでコメントアウト中です
			if (strstr(_baseFilePath, "Player") && FileRead_eof(mBaseHandle) == 0) {
				LoadChara(mBaseHandle, mGrowthHandle,eChara;);
			}
			else if (strstr(_baseFilePath, "Enemy") && FileRead_eof(mBaseHandle) == 0) {
				LoadChara(mBaseHandle, mGrowthHandle,eEnemy);
			}
			else if(strstr(_baseFilePath, "Fairy") && FileRead_eof(mBaseHandle) == 0){
				LoadWeapon(int _baseHandle, int _growthHandle, eFairy);
			}
			*/
		}
	}

	FileRead_close(mBaseHandle);
	FileRead_close(mGrowthHandle);
	return 0;
}


/**************************************************************************
型:int
引数:const char* _baseHandle…読み込むファイルのハンドル
	 const char* _growthHandle…読み込むファイルのハンドル
　　 vector<Mass>& _unit…基礎ステータスと成長後ステータスを格納する
***************************************************************************/
int Load::LoadChara(int _baseHandle, int _growthHandle, vector<Unit>& _unit) {
	//int Load::LoadChara(int _baseHandle, int _growthHandle, int _type) {
	int n = 0;
	int nn = 0;

	while (FileRead_eof(mBaseHandle) == 0) {
		while (FileRead_eof(mBaseHandle) == 0) {  //ファイルの終端まで

			LoadFile(mBaseHandle, input);  //データ読み込み

			switch (n) {
			case 0:strcpy(mName, input); break;
			case 1:mRole = eRole(atoi(input)); break;
			case 2:mHp = atoi(input); break;
			case 3:mStr = atoi(input); break;
			case 4:mDef = atoi(input); break;
			case 5:mIntelli = atoi(input); break;
			case 6:mMnd = atoi(input); break;
			case 7:mDex = atoi(input); break;
			case 8:mAgi = atoi(input); break;
			case 9:mMove = atoi(input); break;
			case 10:
				if (strstr(input, "/") == NULL) {
					break;
				}
				else {
					strcpy(mFilePath, input); break;
				}
			}

			n++;
			if (n == 11) {
				_unit.emplace_back(Unit(mName, mRole, mHp, mStr, mDef, mIntelli, mMnd, mDex, mAgi, mMove, 0, 0));
				/*最新版更新時の処理　まだ最新版が上がってないのでコメントアウト中です
				switch(_type){
				case eChara:INSTANCE::SetCharadata(Unit(name, mRole, mHp, mStr, mDef, mIntelli, mMnd, mDex, mAgi, mMove, 0, 0)); break;
				case eEnemy:INSTANCE::SetEnemydata(Unit(name, mRole, mHp, mStr, mDef, mIntelli, mMnd, mDex, mAgi, mMove, 0, 0)); break;
				}
				*/
				n = 0;
				break;
			}
		}
		while (FileRead_eof(mGrowthHandle) == 0) {  //ファイルの終端まで

			LoadFile(mGrowthHandle, input);  //データ読み込み	

			switch (nn) {
			case 0:mGrowthHp = atof(input); break;
			case 1:mGrowthStr = atof(input); break;
			case 2:mGrowthDef = atof(input); break;
			case 3:mGrowthIntelli = atof(input); break;
			case 4:mGrowthMnd = atof(input); break;
			case 5:mGrowthDex = atof(input); break;
			case 6:mGrowthAgi = atof(input); break;
			}
			nn++;
			if (nn == 7) {
				_unit[_unit.size() - 1].SetGrowth(mGrowthHp, mGrowthStr, mGrowthDef, mGrowthIntelli, mGrowthMnd, mGrowthDex, mGrowthAgi);
				nn = 0;
				break;
			}
		}
	}
	return 0;
}

/**************************************************************************
型:int
引数:const char* _baseHandle…読み込むファイルのハンドル
	 const char* _growthHandle…読み込むファイルのハンドル
　　 vector<Mass>& _unit…基礎ステータスと成長後ステータスを格納する
***************************************************************************/
//int Load::LoadWeapon(int _baseHandle, int _growthHandle, int type) {
int Load::LoadWeapon(int _baseHandle, int _growthHandle, vector<Unit>& _unit) {
	int n = 0, nn = 0;

	while (FileRead_eof(mBaseHandle) == 0) {
		while (FileRead_eof(mBaseHandle) == 0) {  //ファイルの終端まで
			LoadFile(mBaseHandle, input);  //データ読み込み

			switch (n) {
			case 0:strcpy(mName, input); break;
			case 1:mRangeMin = atoi(input); break;
			case 2:mRangeMax = atoi(input); break;
			case 3:mRole = eRole(atoi(input)); break;
			case 4:mHp = atoi(input); break;
			case 5:mStr = atoi(input); break;
			case 6:mDef = atoi(input); break;
			case 7:mIntelli = atoi(input); break;
			case 8:mMnd = atoi(input); break;
			case 9:mDex = atoi(input); break;
			case 10:mAgi = atoi(input); break;
			case 11:mMove = atoi(input); break;
			}

			n++;

			if (n == 12) {
				_unit.emplace_back(Unit(mName, mRole, mHp, mStr, mDef, mIntelli, mMnd, mDex, mAgi, mMove, 0, 0));

				/*最新版更新時の処理　まだ最新版が上がってないのでコメントアウト中です
				INSTANCE::SetFairyDate(Unit(name, mRole, mHp, mStr, mDef, mIntelli, mMnd, mDex, mAgi, mMove, 0, 0)); break;
				*/
				n = 0;
				break;
			}
		}
		while (FileRead_eof(mGrowthHandle) == 0) {  //ファイルの終端まで
			LoadFile(mGrowthHandle, input);  //データ読み込み	

			switch (nn) {
			case 0:mGrowthHp = atof(input); break;
			case 1:mGrowthStr = atof(input); break;
			case 2:mGrowthDef = atof(input); break;
			case 3:mGrowthIntelli = atof(input); break;
			case 4:mGrowthMnd = atof(input); break;
			case 5:mGrowthDex = atof(input); break;
			case 6:mGrowthAgi = atof(input); break;
			}
			nn++;
			if (nn == 7) {
				_unit[_unit.size() - 1].SetGrowth(mGrowthHp, mGrowthStr, mGrowthDef, mGrowthIntelli, mGrowthMnd, mGrowthDex, mGrowthAgi);
				nn = 0;
				break;
			}
		}
	}
	return 0;
}