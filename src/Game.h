#pragma once
#include "Grid.h"
#include "LBlock.cpp"
#include "JBlock.cpp"
#include "IBlock.cpp"
#include "OBlock.cpp"
#include "SBlock.cpp"
#include "TBlock.cpp"
#include "ZBlock.cpp"

class Game
{
public:
    Game();

    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void Draw();

    Grid grid;

private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};