#include "Parameter.h"


//���E�̃��[���̒l���߂�t�@�C��
const float MAX_ENERGY = 10.0;		//�t�B�[���h�̃}�b�N�X�G�l���M�[
const float MAX_RE_ENERGY = 0.1;	//�t�B�[���h�̃}�b�N�X���G�l
const int MAX_LABEL_NUM = 10;		//�h���̐�

//�N���[�`���[�̐F
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