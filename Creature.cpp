#include "Creature.h"

//�s���̕���@���ǂ��Ă���
float Creature::EvaluationFunction(Environment env) {
	return env.energy;
}

void Creature::Update() {
	//�����钆�ň�Ԃ����̂�I��
	float value = -1;
	int X = 0, Y = 0;
	for (int i = (int)-moveRate; i <= (int)moveRate; i++) {
		for (int j = (int)-moveRate; j <= (int)moveRate; j++) {
			float v = EvaluationFunction(world->CheckEnvironment(x + i, y + j));
			if (value < v) {
				X = (int)(x + i);
				Y = (int)y + j;
				value = v;
			}
		}
	}

	//�����@�����I�ɂ͍U���̕����Ƃ�������
	x = (float)X;
	y = (float)Y;
}


void Creature::Reaction() {
	Environment &tmp = world->GetEnvironment(x, y);		//tmp��filed[x][y]�𑀍�ł��邱�Ƃɒ���
	energy += tmp.energy;
	life += tmp.energy/(float)5.0;
	tmp.energy = 0;
	if (energy > bornRate) {
		world->AddCreature(label, x, y, (float)GetRand(3)+1);
		energy -= bornRate;
	}
	life -= consumption;
}

void Creature::Draw(int cellSize, cv::Mat &img){
	cv::circle(img, cv::Point((int)((x + 0.5)*cellSize), (int)((y + 0.5)*cellSize)), (int)size, colorHandle[label], -1);
}