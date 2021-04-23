#pragma once
#include "Command.h"
class Delete :
    public Command
{
    int deletedVal;
public:
    Delete(Board& _board, int col = 0, int row = 0) :Command(_board, col, row) { deletedVal = 0; }
    bool Execute();
    bool Undo();
};

