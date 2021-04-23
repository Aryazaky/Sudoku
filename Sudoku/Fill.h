#pragma once
#include "Command.h"
class Fill :
    public Command
{
    int value;
    int prevVal;
public:
    Fill(Board& _board, int val = 0, int col = 0, int row = 0) :Command(_board, col, row) { 
        value = val;
        prevVal = _board.GetValue(col,row);
    }
    bool Execute();
    bool Undo();
};

