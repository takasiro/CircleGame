#include "SceneMgr.h"
#include"TitleScene.h"


SceneMgr::SceneMgr(){
	//初期シーン設定
	AddScene((BaseScene*)new TitleScene(this));
}


SceneMgr::~SceneMgr(){

}
