#include "Sudoku.h"
#include<iostream>
#include<conio.h>

void Sudoku::GameLoop()
{
    while (!CheckWin())
    {
        KeyInput();
        DisplayGame();
    }
}

void Sudoku::DisplayGame()
{
}

void Sudoku::KeyInput()
{
    if (_kbhit()) {
        char ch = _getch();
        switch (ch)
        {
        case'a':
            cursor.x--;
            if (cursor.x < 0) {
                cursor.x = board.GetSize() - 1;
            }
            break;
        case'd':
            cursor.x++;
            if (cursor.x >= board.GetSize()) {
                cursor.x = 0;
            }
            break;
        case's':
            cursor.y--;
            if (cursor.y < 0) {
                cursor.y = board.GetSize() - 1;
            }
            break;
        case'w':
            cursor.y++;
            if (cursor.y >= board.GetSize()) {
                cursor.y = 0;
            }
            break;
        default:
            break;
        }
    }
}

void Sudoku::ActionFill()
{
    commands.Push(new Fill(board, number, cursor.x, cursor.y));
}

void Sudoku::ActionRemove()
{
    commands.Push(new Delete(board, cursor.x, cursor.y));
}

void Sudoku::UndoAction()
{
    commands.Pop();
}

void Sudoku::RedoAction()
{
    commands.Repush();
}

bool Sudoku::CheckWin()
{
    return board.CheckAnswer();
}

Sudoku::Sudoku()
{
    cursor = { 0, 0 };
    number = 0;
}

void Sudoku::StartGame()
{
    GameLoop();
}
