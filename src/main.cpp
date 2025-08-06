#include "raylib.h"
#include "Grid.h"

int main()
{
	// Create the window and OpenGL context
	InitWindow(300, 600, "Tetris");

	SetTargetFPS(60);

	Color darkBlue = {44, 44, 127, 255};

	Grid grid;
	grid.grid[0][0] = 1;
	grid.grid[3][5] = 4;
	grid.grid[17][8] = 7;

	// game loop
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(darkBlue);
		grid.Draw();

		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
