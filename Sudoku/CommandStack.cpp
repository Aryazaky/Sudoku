#include "CommandStack.h"

CommandStack::CommandStack()
{
	History = new std::stack<Command>();
	RedoStack = new std::stack<Command>();
}
