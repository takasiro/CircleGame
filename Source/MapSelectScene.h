#include "BaseScene.h"

class MapSelectScene : public BaseScene {

	MapSelectScene();
	MapSelectScene(ISceneChanger*);
	virtual	~MapSelectScene();
	int Initialize() { return 0; }	//初期化処理
	int Update() { return 0; }		//計算処理
	int Draw() { return 0; }			//描画処理
	int Close() { return 0; }		//終了処理


};