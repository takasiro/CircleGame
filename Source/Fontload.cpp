#include "Fontcall.h"
#include <iostream>
using namespace std;
Fontcall::Fontcall() {
		Font[0] = CreateFontToHandle("HG丸ｺﾞｼｯｸM-PRO", 15, 1, DX_FONTTYPE_ANTIALIASING_EDGE);
		Font[1] = CreateFontToHandle("メイリオ", 15, 1, DX_FONTTYPE_ANTIALIASING_EDGE);
		Font[2] = CreateFontToHandle("DragonQuestFC", 15, 1, DX_FONTTYPE_ANTIALIASING_EDGE);
		Font[3] = CreateFontToHandle("游明朝 Demibold", 15, 1, DX_FONTTYPE_ANTIALIASING_EDGE);
		Font[4] = CreateFontToHandle("Algerian", 15, 1, DX_FONTTYPE_ANTIALIASING_EDGE);
}
Fontcall::~Fontcall() {
}
int Fontcall::Initialize() {
	return 0;
}
int Fontcall::Update() {
	return 0;
}
int Fontcall::Draw() {
	return 0;
}
int Fontcall::Close() {
	return 0;
}
int Fontcall::FontNum(int FontNum) {
	return Font[FontNum];
}