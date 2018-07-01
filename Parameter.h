#pragma once

#include "MyOpenCV.h"

//世界のルール
extern const float MAX_ENERGY;
extern const float MAX_RE_ENERGY;
extern const int MAX_LABEL_NUM;

//クリーチャーの色
extern const cv::Scalar colorHandle[10];
int GetRand(int num);