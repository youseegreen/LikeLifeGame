#pragma once
#include <DxLib.h>

class Window {
private:
	static int screenX;
	static int screenY;
public:
	Window() {};

	static void Initialize(int x, int y) {
		screenX = x;
		screenY = y;
		ChangeWindowMode(TRUE);
		SetWindowSizeChangeEnableFlag(TRUE, TRUE);
		SetGraphMode(screenX, screenY, 32);
		if (DxLib_Init() == -1) {
			//ó·äOèàóù
		};
		SetDrawScreen(DX_SCREEN_BACK);         //äÓñ{ê›íË
	}

	static void SetWindow(int x, int y) {
		screenX = x;
		screenY = y;
		SetGraphMode(screenX, screenY, 32);
		SetWindowSizeChangeEnableFlag(TRUE, TRUE);
	}
};

int Window::screenX;
int Window::screenY;