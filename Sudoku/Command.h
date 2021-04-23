#pragma once
#include"Board.h"
class Command
{
protected:
	int colX;
	int rowY;
	Board* board;
public:
	Command(Board& _board, int col = 0, int row = 0) {
		colX = col;
		rowY = row;
		board = &_board;
	}
	virtual bool Execute() = 0;
	virtual bool Undo() = 0;
};

