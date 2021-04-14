#include "Board.h"

void Board::FillBoard() {
	std::string temp_answer = answer;
	if (size > 0 && temp_answer.size() >= (size * size)) {
		int i = size, o = size;
		while (i--) {
			std::vector<Cell> temp;
			while (o--) {
				Cell cell;
				cell.value = temp_answer.back() - '0';
				cell.is_constant = false;
				if (rand() % 10 > 4) {
					cell.is_constant = true;
				}
				temp.push_back(cell);
				temp_answer.pop_back();
			}
			board.push_back(temp);
			answer_board.push_back(temp);
		}
	}
}

void Board::ClearNonConstants()
{
	for (std::vector<Cell>& cells_list : board) {
		for (Cell& cell : cells_list) {
			if (!cell.is_constant) {
				cell.value = 0;
			}
		}
	}
}

Board::Board()
{
	srand(time(NULL));
	size = 9;
	answer = "217386495346759281598421763451238679739164852862975314975843126124697538683512947";
	FillBoard();
	ClearNonConstants();
}

Board::Board(std::string _answer, int _size)
{
	srand(time(NULL));
	size = _size;
	answer = _answer;
	FillBoard();
	ClearNonConstants();
}

bool Board::SetValue(int col, int row, int val)
{
	if (!board[col][row].is_constant) {
		board[col][row].value = val;
		return true;
	}
	return false;
}
