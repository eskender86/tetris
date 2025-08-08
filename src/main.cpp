#include "raylib.h"
#include "Grid.h"
#include "LBlock.cpp"
#include "TBlock.cpp"

int main()
{
	// Create the window and OpenGL context
	InitWindow(300, 600, "Tetris");

	SetTargetFPS(60);

	Color darkBlue = {44, 44, 127, 255};

	Grid grid;

	TBlock block = TBlock();

	// game loop
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(darkBlue);
		grid.Draw();
		block.Draw();
		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
