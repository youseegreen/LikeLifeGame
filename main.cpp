#include <iostream>

#include "Window.h"
#include "World.h"
//#include "Creature.h"

int main()
{
	Window::Initialize(1000, 500);
	World world(1000,500);
	world.MainRoop();
	DxLib_End();
}