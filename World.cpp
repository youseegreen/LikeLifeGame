#include "World.h"

//参照を返すことに注意
Environment &World::GetEnvironment(float x, float y) const{
	int u = (int)(x + 0.5);
	int v = (int)(y + 0.5);
	if (u < 0 || u >= worldX || v < 0 || v >= worldY)return field[worldX / 2][worldY / 2];
	return field[u][v];
}
Environment World::CheckEnvironment(float x, float y) const{
	int u = (int)(x + 0.5);
	int v = (int)(y + 0.5);
	if (u < 0 || u >= worldX || v < 0 || v >= worldY)return Environment();
	return field[u][v];
}

void World::UpdateField() {
	for (int y = 0; y < worldY; y++) {
		for (int x = 0; x < worldX; x++) {
			field[x][y].energy += field[x][y].re_energy;
			if (field[x][y].energy > MAX_ENERGY)field[x][y].energy = MAX_ENERGY;
		}
	}
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
//		WaitKey();
		WaitTimer(300);
	}
}

void World::AddCreature(int lab, float x, float y, float move, float life) {
	x += GetRand(20) - 10;
	y += GetRand(20) - 10;
	creatureList.push_front(new Creature(this, lab, life, x, y, move));
}




//青：少ない　緑：多い
void Environment::Draw(int x, int y, int size) const {
	int tmp = (int)(energy / MAX_ENERGY * 255);
	DrawBox(x * size, y * size, (x + 1) * size, (y + 1) * size,
		GetColor(0, tmp, 255 - tmp), TRUE);
}

void World::DrawScreen() const {
	ClearDrawScreen();

	//fieldの描画
	for (int y = 0; y < worldY; y++) {
		for (int x = 0; x < worldX; x++) {
			field[x][y].Draw(x, y, size);
		}
	}

	//生物の描画
	for (auto itr : creatureList) itr->Draw(size);

	ScreenFlip();
}

//青：エネルギー　緑：回復率
void World::LoadFieldMap(const char *fName = "map\\map.bmp") {
	cv::Mat img = cv::imread(fName, 1);
	if (img.data == NULL)return;
	int w = img.cols, h = img.rows, ch = img.channels(), step = img.step;

	for (int y = 0; y < worldY; y++) {
		for (int x = 0; x < worldX; x++) {
			field[x][y].energy =
				img.data[(y * h / worldY)*step + (x * w / worldX) * ch + 0] / 255.0 * MAX_ENERGY;
			field[x][y].re_energy =
				img.data[(y * h / worldY)*step + (x * w / worldX) * ch + 1] / 255.0 * MAX_RE_ENERGY;
			//乱数かけておく
			//0.7~1.0を出す乱数
			field[x][y].energy *= GetRand(300) / 1000.0 + 0.7;
			field[x][y].re_energy *= GetRand(300) / 1000.0 + 0.7;
		}
	}
}
