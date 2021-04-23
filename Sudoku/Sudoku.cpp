#include "Sudoku.h"
#include<iostream>
#include<conio.h>

void Sudoku::GameLoop()
{
    bool gameOver = false;
    while (!gameOver)
    {
        if (KeyInput(keys)) {
            gameOver = CheckWin();
        }
    }
}

void Sudoku::DisplayGame()
{
    std::cout << keys.TutorialText() << std::endl << board.BoardAsString() << std::endl;
}

// Return apakah harus ngecek win atau ngga
bool Sudoku::KeyInput(const ControlScheme& key)
{
    // Ndak tau cara lain selai else if else if else if
    // Swicth(ch) ndak bisa soalnya case minta constant value
    if (_kbhit()) {
        char ch = _getch();
        if (ch == key.up) 
        {
            cursor.y++;
            if (cursor.y >= board.GetSize()) {
                cursor.y = 0;
            }
            DisplayGame();
            return false;
        }
        else if (ch == key.left)
        {
            cursor.x--;
            if (cursor.x < 0) {
                cursor.x = board.GetSize() - 1;
            }
            DisplayGame();
            return false;
        }
        else if (ch == key.down)
        {
            cursor.y--;
            if (cursor.y < 0) {
                cursor.y = board.GetSize() - 1;
            }
            DisplayGame();
            return false;
        }
        else if (ch == key.right)
        {
            cursor.x++;
            if (cursor.x >= board.GetSize()) {
                cursor.x = 0;
            }
            DisplayGame();
            return false;
        }
        else if (ch == key.enter_num)
        {
            std::cout << "Angka: ";
            std::cin >> number;
            ActionFill();
            DisplayGame();
            return true;
        }
        else if (ch == key.remove_num)
        {
            ActionRemove();
            DisplayGame();
            return false;
        }
        else if (ch == key.undo)
        {
            UndoAction();
            DisplayGame();
            return true;
        }
        else if (ch == key.redo)
        {
            RedoAction();
            DisplayGame();
            return true;
        }
    }
}

void Sudoku::ActionFill()
{
    if (number >= 1 && number <= 9) {
        commands.Push(new Fill(board, number, cursor.x, cursor.y));
    }
    else
    {
        std::cout << "Angka yang dipilih diluar range!";
    }
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
    keys = { 'w','a','s','d','q','e','z','x' };
    number = 0;
}

void Sudoku::StartGame()
{
    GameLoop();
}
