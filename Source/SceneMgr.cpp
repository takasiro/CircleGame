#include "SceneMgr.h"



SceneMgr::SceneMgr(){
	//初期シーン設定
	AddScene((BaseScene*)new TitleScene(this));
}


SceneMgr::~SceneMgr(){

}
