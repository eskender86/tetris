#include "raylib.h"
#include "Game.h"

int main()
{
	// Create the window and OpenGL context
	InitWindow(300, 600, "Tetris");
	SetTargetFPS(60);
	Color darkBlue = {44, 44, 127, 255};

	Game game = Game();

	// game loop
	while (!WindowShouldClose())
	{
		game.HandleInput();

		BeginDrawing();
		ClearBackground(darkBlue);

		game.Draw();

		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
