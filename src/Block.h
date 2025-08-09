#pragma once
#include <vector>
#include <map>

#include "Position.h"
#include "Color.h"

class Block
{
public:
    Block();

    void Draw();
    void Move(int rows, int columns);
    void Rotate();
    void UnRotation();

    std::vector<Position> GetCellPositions();

    int id;
    std::map<int, std::vector<Position>> cells;

private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};