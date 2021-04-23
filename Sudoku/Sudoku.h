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
	struct ControlScheme
	{
		char up;
		char left;
		char down;
		char right;
		char enter_num;
		char remove_num;
		char undo;
		char redo;
		std::string TutorialText() {
			return std::string()
				+ "--Control Scheme--"
				+ "\nUp: \t" + up
				+ "\nLeft: \t" + left
				+ "\nDown: \t" + down
				+ "\nRight: \t" + right
				+ "\nEnter num on selected: \t" + enter_num
				+ "\nRemove num on selected: \t" + remove_num
				+ "\nUndo: \t" + undo
				+ "\nRedo: \t" + redo;
		}
	};
	ControlScheme keys;
	Cursor cursor;
	int number;
	void GameLoop();
	void DisplayGame();
	bool KeyInput(const ControlScheme& key);
	void ActionFill();
	void ActionRemove();
	void UndoAction();
	void RedoAction();
	bool CheckWin();
public:
	Sudoku();
	void StartGame();
};

