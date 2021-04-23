#pragma once
#include"Board.h"
#include"CommandStack.h"
#include"Fill.h"
#include"Delete.h"
class Sudoku
{
private:
	Board board;
	CommandStack commands;
	struct Cursor {
		int x;
		int y;
	};
	Cursor cursor;
	int number;
	void GameLoop();
	void DisplayGame();
	void KeyInput();
	void ActionFill();
	void ActionRemove();
	void UndoAction();
	void RedoAction();
	bool CheckWin();
public:
	Sudoku();
	void StartGame();
};

