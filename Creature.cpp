#include "Creature.h"

//行動の方策　改良していく
float Creature::EvaluationFunction(Environment env) {
	return env.energy;
}

void Creature::Update() {
	//動ける中で一番いいのを選ぶ
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

	//動く　将来的には攻撃の方向とかもする
	x = X;
	y = Y;
}


void Creature::Reaction() {
	Environment &tmp = world->GetEnvironment(x, y);		//tmpはfiled[x][y]を操作できることに注意
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