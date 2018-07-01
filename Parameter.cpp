#include "Parameter.h"


//世界のルールの値決めるファイル
const float MAX_ENERGY = 10.0;		//フィールドのマックスエネルギー
const float MAX_RE_ENERGY = 0.1;	//フィールドのマックスリエネ
const int MAX_LABEL_NUM = 10;		//派閥の数

//クリーチャーの色
const int colorHandle[10] = {
	GetColor(255,0,0),
	GetColor(255, 255, 0),
	GetColor(255,0,255),
	GetColor(255,128,0),
	GetColor(255,0,128),
	GetColor(128,255,0),
	GetColor(128,128,0),
	GetColor(128,0,255),
	GetColor(128,0,128),
	GetColor(255,255,255)
};