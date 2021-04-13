#pragma once
#include "Command.h"
#include <stack>
class CommandStack
{
public:
	std::stack<Command> *History;
	std::stack<Command> *RedoStack;
	CommandStack();
};

