#pragma once

using namespace std;
class Creature;

#include <list>
#include <random>
#include "Creature.h"
#include <DxLib.h>

struct Environment {
	float energy;
	float re_energy;
};

class World {
	const int sizeX;
	const int sizeY;
	list<Creature *> creatureList;

	//•ª‚¯‚½‚Ù‚¤‚ª—Ç‚¢
	
	Environment **field;
	void UpdateField();
	void DrawScreen(); 

public:
	World(int sX, int sY) :sizeX(sX),sizeY(sY){
		field = new (Environment *[sX]);
		for (int i = 0; i < sX; i++) field[i] = new(Environment[sY]);
		
		for (int y = 0; y < sizeY; y++) {
			for (int x = 0; x < sizeX; x++) {
				field[x][y].energy = GetRand(100);
				field[x][y].re_energy = GetRand(10);
			}
		}

		for (int i = 0; i < 10; i++) {
			AddCreature(GetRand(3), GetRand(sX), GetRand(sY));
		}
	}

	void MainRoop();
	void Update();
	void AddCreature(int lab, float x = 0, float y = 0, float vx = 0, float vy = 0, float life = 10.0);
	Environment &GetEnvironment(float x, float y);
	Environment CheckEnvironment(float x, float y);
};