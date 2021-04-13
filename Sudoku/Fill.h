#pragma once
#include "Command.h"
class Fill :
    public Command
{
    int colX;
    int rowY;
    int value;
public:
    void Execute();
    void Undo();
};

