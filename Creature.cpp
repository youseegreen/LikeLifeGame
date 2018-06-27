#include "Creature.h"

float Creature::EvaluationFunction(Environment env) {
	return env.energy;
}

void Creature::Update() {
	//“®‚¯‚é’†‚Åˆê”Ô‚¢‚¢‚Ì‚ð‘I‚Ô
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

	//“®‚­@«—ˆ“I‚É‚ÍUŒ‚‚Ì•ûŒü‚Æ‚©‚à‚·‚é
	x = X;
	y = Y;
}


void Creature::Reaction() {
	Environment &tmp = world->GetEnvironment(x, y);		//tmp‚Ífiled[x][y]‚ð‘€ì‚Å‚«‚é‚±‚Æ‚É’ˆÓ
	energy += tmp.energy;
	life += tmp.energy;
	tmp.energy = 0;
	if (energy > bornRate) {
		world->AddCreature(label, x, y);
		energy -= bornRate;
	}
	life -= consumption;
}