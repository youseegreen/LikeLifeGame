#include "Parameter.h"
#include <random>

//���E�̃��[���̒l���߂�t�@�C��
const float MAX_ENERGY = (float)10.0;		//�t�B�[���h�̃}�b�N�X�G�l���M�[
const float MAX_RE_ENERGY = (float)0.1;	//�t�B�[���h�̃}�b�N�X���G�l
const int MAX_LABEL_NUM = 10;		//�h���̐�

//�N���[�`���[�̐F
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

//DxLib��GetRand()�̑���
int GetRand(int num) {
	return rand() % num;
}