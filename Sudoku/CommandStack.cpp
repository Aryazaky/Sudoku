#include "CommandStack.h"

CommandStack::CommandStack()
{

}

CommandStack::~CommandStack()
{

}

void CommandStack::Push(Command* command)
{
	History.push(command);
	command->Execute();
}

void CommandStack::Pop()
{
	RedoStack.push(History.top());
	History.top()->Undo();
	History.pop();
}

void CommandStack::Repush()
{
	History.push(RedoStack.top());
	History.top()->Execute();
	RedoStack.pop();
}
