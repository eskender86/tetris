#include "Game.h"
#include <iostream>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;
}

Block Game::GetRandomBlock()
{
    // Seed the random number generator
    srand(time(NULL));

    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }

    int randomIndex = (rand() % blocks.size());

    Block block = blocks[randomIndex];

    blocks.erase(blocks.begin() + randomIndex);

    return block;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();

    if (gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }

    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        UpdateScore(0, 1);
        break;
    case KEY_UP:
        RotateBlock();
        break;
    }
}

void Game::MoveBlockLeft()
{
    if (gameOver)
        return;

    currentBlock.Move(0, -1);

    if (IsBlockOutside() || !BlockFits())
        currentBlock.Move(0, 1);
}

void Game::MoveBlockRight()
{
    if (gameOver)
        return;

    currentBlock.Move(0, 1);

    if (IsBlockOutside() || !BlockFits())
        currentBlock.Move(0, -1);
}

void Game::MoveBlockDown()
{
    if (gameOver)
        return;

    currentBlock.Move(1, 0);

    if (IsBlockOutside() || !BlockFits())
    {
        currentBlock.Move(-1, 0);
        LockBlock();
    }
}

bool Game::GetGameOver()
{
    return gameOver;
}

int Game::GetScore()
{
    return score;
}

bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();

    for (Position item : tiles)
    {
        if (grid.IsCellOutside(item.row, item.column))
            return true;
    }

    return false;
}

void Game::RotateBlock()
{
    if (gameOver)
        return;

    currentBlock.Rotate();

    if (IsBlockOutside() || !BlockFits())
    {
        currentBlock.UnRotation();
    }
}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();

    for (Position item : tiles)
    {
        grid.grid[item.row][item.column] = currentBlock.id;
    }

    currentBlock = nextBlock;

    gameOver = !BlockFits();

    nextBlock = GetRandomBlock();

    int rowsCleared = grid.ClearFullRows();
    UpdateScore(rowsCleared, 0);
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();

    for (Position item : tiles)
    {
        if (!grid.IsCellEmpty(item.row, item.column))
            return false;
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}

void Game::UpdateScore(int lineCleared, int moveDownPoints)
{
    switch (lineCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
    }

    score += moveDownPoints;
}
