#include "Parameter.h"
#include <random>

//世界のルールの値決めるファイル
const float MAX_ENERGY = (float)10.0;		//フィールドのマックスエネルギー
const float MAX_RE_ENERGY = (float)0.1;	//フィールドのマックスリエネ
const int MAX_LABEL_NUM = 10;		//派閥の数

//クリーチャーの色
const cv::Scalar colorHandle[10] = {
	cv::Scalar(255,0,0),
	cv::Scalar(255, 255, 0),
	cv::Scalar(255,0,255),
	cv::Scalar(255,128,0),
	cv::Scalar(255,0,128),
	cv::Scalar(128,255,0),
	cv::Scalar(128,128,0),
	cv::Scalar(128,0,255),
	cv::Scalar(128,0,128),
	cv::Scalar(255,255,255)
};

//DxLibのGetRand()の代わり
int GetRand(int num) {
	return rand() % num;
}