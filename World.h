#pragma once

using namespace std;
class Creature;

#include <list>
#include <random>
#include "Parameter.h"
#include "Creature.h"

struct Environment {
	float energy;
	float re_energy;
	void Draw(int x,int y,int size)const;
};

class World {
	const int worldX;
	const int worldY;
	const int size;	//cellのsize

	list<Creature *> creatureList;

	void DrawScreen()const;

	//field系
	Environment **field;
	void UpdateField();

public:
	World(int sX, int sY, int tsize) :worldX(sX/tsize),worldY(sY/tsize),size(tsize){
		//フィールドの生成
		field = new (Environment *[worldX]);
		for (int i = 0; i < worldX; i++) field[i] = new(Environment[worldY]);
		LoadFieldMap("map\\map.bmp");

		//生物の生成
		for (int i = 0; i < MAX_LABEL_NUM; i++) {
			AddCreature(i, GetRand(worldX), GetRand(worldY), GetRand(3) + 1);
			AddCreature(i, GetRand(worldX), GetRand(worldY), GetRand(3) + 1);
		}
	}

	//デストラクタ
	~World() {
		for (int i = 0; i < worldX; i++)delete[] field[i];
		delete[] field;
		//生物全滅で終了で、生物の解放は生物側がやるからdeleteいらん
	}
	
	void LoadFieldMap(const char *fName);	//マップからフィールド生成
	void MainRoop();	//ゲーム本体
	void Update();		//1時刻進める
	void AddCreature(int lab, float x = 0, float y = 0, float move = 1, float life = 10.0);
	Environment &GetEnvironment(float x, float y)const;
	Environment CheckEnvironment(float x, float y)const;
};