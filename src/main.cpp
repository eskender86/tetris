#include "raylib.h"
#include "Game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
	double currentTime = GetTime();

	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}

	return false;
}

int main()
{
	Color darkBlue = {44, 44, 127, 255};
	// Create the window and OpenGL context
	InitWindow(300, 600, "Tetris");
	SetTargetFPS(60);

	Game game = Game();

	// game loop
	while (!WindowShouldClose())
	{
		game.HandleInput();

		if (EventTriggered(0.2))
			game.MoveBlockDown();

		BeginDrawing();
		ClearBackground(darkBlue);

		game.Draw();

		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
