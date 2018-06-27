#include "World.h"

void World::UpdateField() {
	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			field[x][y].energy += field[x][y].re_energy;
		}
	}
}

void World::DrawScreen() {
	ClearDrawScreen();
	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			DrawBox(x, y, x + 1, y + 1, GetColor(0, 0, field[x][y].energy), TRUE);
		}
	}
	for (auto itr : creatureList) {
		itr->Draw();
	}
	ScreenFlip();
}

void World::Update() {
	//fieldの更新
	UpdateField();

	//生物の移動
	for (auto itr : creatureList) {
		itr->Update();
	}
	//相互干渉を計算
	for (auto itr : creatureList) {
		itr->Reaction();
		if (!itr->IsLife()) {
			//死んだら外す
			auto tmp = itr;
			creatureList.remove(itr);
			delete tmp;
		}
	}
	DrawScreen();
}

void World::MainRoop() {
	while (creatureList.size() > 0) {
		Update();
		WaitKey();
	}
}


void World::AddCreature(int lab, float x, float y, float vx, float vy, float life) {
	x += GetRand(20) - 10;
	y += GetRand(20) - 10;
	creatureList.push_front(new Creature(this, lab, life, x, y, vx, vy));
}


Environment &World::GetEnvironment(float x, float y) {
	int u = (int)(x + 0.5);
	int v = (int)(y + 0.5);
	if (u < 0 || u >= sizeX || v < 0 || v >= sizeY)return field[sizeX/2][sizeY/2];
	return field[u][v];
}
Environment World::CheckEnvironment(float x, float y) {
	int u = (int)(x + 0.5);
	int v = (int)(y + 0.5);
	if (u < 0 || u >= sizeX || v < 0 || v >= sizeY)return Environment();
	return field[u][v];
}