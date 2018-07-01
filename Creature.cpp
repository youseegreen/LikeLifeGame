#include "Creature.h"

//�s���̕���@���ǂ��Ă���
float Creature::EvaluationFunction(Environment env) {
	return env.energy;
}

void Creature::Update() {
	//�����钆�ň�Ԃ����̂�I��
	float value = -1;
	int X = 0, Y = 0;
	for (int i = -moveRate; i <= moveRate; i++) {
		for (int j = -moveRate; j <= moveRate; j++) {
			float v = EvaluationFunction(world->CheckEnvironment(x + i, y + j));
			if (value < v) {
				X = x + i;
				Y = y + j;
				value = v;
			}
		}
	}

	//�����@�����I�ɂ͍U���̕����Ƃ�������
	x = X;
	y = Y;
}


void Creature::Reaction() {
	Environment &tmp = world->GetEnvironment(x, y);		//tmp��filed[x][y]�𑀍�ł��邱�Ƃɒ���
	energy += tmp.energy;
	life += tmp.energy/5.0;
	tmp.energy = 0;
	if (energy > bornRate) {
		world->AddCreature(label, x, y, GetRand(3)+1);
		energy -= bornRate;
	}
	life -= consumption;
}

void Creature::Draw(int cellSize = 1){
	DrawCircle(x*cellSize + 0.5 * cellSize, y*cellSize + 0.5 * cellSize, 
				size, colorHandle[label]);
}