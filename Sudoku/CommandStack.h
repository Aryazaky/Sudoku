#pragma once
#include "Command.h"
#include <stack>
class CommandStack
{
private:
	std::stack<Command*> History;
	std::stack<Command*> RedoStack;
public:
	CommandStack();
	~CommandStack();

	void Push(Command* command);
	void Pop();
	void Repush();
};

