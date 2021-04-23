#pragma once
#include <vector>
#include <string>
#include <time.h>

class Board
{
	static int size;
	struct Cell {
		int value;
		bool is_constant;
	};
	std::vector<std::vector<Cell>> board, answer_board;
	std::string answer;

	void FillBoard();
	void ClearNonConstants();
public:
	Board();
	Board(std::string _answer, int _size);
	bool SetValue(int col, int row, int val);
	int GetValue(int col, int row);
	bool CheckAnswer();
	int GetSize();
	std::string BoardAsString();
};

