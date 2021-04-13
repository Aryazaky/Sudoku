#pragma once
#include "Command.h"
class Delete :
    public Command
{
    int colX;
    int rowY;
public:
    void Execute();
    void Undo();
};

