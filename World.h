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
	const int size;	//cell��size

	list<Creature *> creatureList;

	void DrawScreen()const;

	//field�n
	Environment **field;
	void UpdateField();

public:
	World(int sX, int sY, int tsize) :worldX(sX/tsize),worldY(sY/tsize),size(tsize){
		//�t�B�[���h�̐���
		field = new (Environment *[worldX]);
		for (int i = 0; i < worldX; i++) field[i] = new(Environment[worldY]);
		LoadFieldMap("map\\map.bmp");

		//�����̐���
		for (int i = 0; i < MAX_LABEL_NUM; i++) {
			AddCreature(i, GetRand(worldX), GetRand(worldY), GetRand(3) + 1);
			AddCreature(i, GetRand(worldX), GetRand(worldY), GetRand(3) + 1);
		}
	}

	//�f�X�g���N�^
	~World() {
		for (int i = 0; i < worldX; i++)delete[] field[i];
		delete[] field;
		//�����S�łŏI���ŁA�����̉���͐���������邩��delete�����
	}
	
	void LoadFieldMap(const char *fName);	//�}�b�v����t�B�[���h����
	void MainRoop();	//�Q�[���{��
	void Update();		//1�����i�߂�
	void AddCreature(int lab, float x = 0, float y = 0, float move = 1, float life = 10.0);
	Environment &GetEnvironment(float x, float y)const;
	Environment CheckEnvironment(float x, float y)const;
};