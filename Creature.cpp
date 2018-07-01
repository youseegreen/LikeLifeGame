#include "Creature.h"

//行動の方策　改良していく
float Creature::EvaluationFunction(Environment env) {
	return env.energy;
}

void Creature::Update() {
	//動ける中で一番いいのを選ぶ
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

	//動く　将来的には攻撃の方向とかもする
	x = (float)X;
	y = (float)Y;
}


void Creature::Reaction() {
	Environment &tmp = world->GetEnvironment(x, y);		//tmpはfiled[x][y]を操作できることに注意
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