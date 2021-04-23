#pragma once
#include"Board.h"
#include"CommandStack.h"
class Sudoku
{
private:
	Board board;
	CommandStack commands;
	int cursor;
	int number;
	void GameLoop();
	void DisplayGame();
	void KeyInput();
	void ActionFill();
	void ActionRemove();
	void UndoAction();
	bool CheckWin();
public:
	Sudoku();
	void StartGame();
};

