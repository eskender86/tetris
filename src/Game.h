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
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();

    Grid grid;
    bool gameOver;

private:
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();

    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};