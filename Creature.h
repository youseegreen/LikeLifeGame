#pragma once

using namespace std;
class World;
struct Environment;

#include "World.h"
#include <DxLib.h>

class Creature {
	float life;		//HP
	int label;		//Team Number
//	float power;	//power
	float energy = 0.0;	//energy
	float moveRate = 1.0;	//動ける範囲/roop
	float consumption = 70.0;	//ライフの消費量
	float bornRate = 10000.0;

	float x, y;		//position 
	float vx, vy;	//velocity

	World *world;	//world

	float size = 3;		//描画サイズ
	
	virtual float EvaluationFunction(Environment env);
	

public:
	Creature() {
		life = 10.0;
		x = y = vx = vy = 0;
		label = 1;
	}

	Creature(World *wor, int lab, float t_life = 10.0, float t_x = 0, float t_y = 0, float t_vx = 0, float t_vy = 0)
		:world(wor),label(lab), life(t_life), x(t_x), y(t_y), vx(t_vx), vy(t_vy) {
	}

	virtual void Update(); 

	virtual void Reaction();

	void Draw() {
		int col;
		if (label % 3 == 0)col = GetColor(255, 0, 0);
		else if (label % 3 == 1)col = GetColor(0, 255, 0);
		else col = GetColor(255, 255, 0);
		DrawCircle(x, y, size, col);
	}

	virtual bool IsLife() { return (life > 0) ? true : false; }
};