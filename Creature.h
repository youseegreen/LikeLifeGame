#pragma once

using namespace std;
class World;
struct Environment;

#include "Parameter.h"
#include "World.h"

class Creature {
	float life = 10;		//HP
	int label;		//Team Number
//	float power;	//power
	float energy = 0.0;	//energy
	float moveRate = 1.0;	//動ける範囲/roop
	float consumption = 1.0;	//ライフの消費量
	float bornRate = 100.0;

	float x, y;		//position 
//	float vx, vy;	//velocity
	float size = 5;		//描画サイズ

	World *world;	//world

	virtual float EvaluationFunction(Environment env);
	
public:
	Creature() {
		life = 10.0;
		x = y = 0;
		label = 1;
	}
	Creature(World *wor, int lab, float t_life = 10.0, float t_x = 0, float t_y = 0, float move = 1)
		:world(wor),label(lab), life(t_life), x(t_x), y(t_y), moveRate(move) { }

	virtual ~Creature() { }
	virtual void Update(); 
	virtual void Reaction();
	virtual void Draw(int cellSize);
	virtual bool IsLife() { return (life > 0) ? true : false; }
};