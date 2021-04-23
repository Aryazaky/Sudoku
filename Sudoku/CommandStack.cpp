#include "CommandStack.h"
#include <iostream>

CommandStack::CommandStack()
{

}

CommandStack::~CommandStack()
{

}

void CommandStack::Push(Command* command)
{
	if (command->Execute()) {
		History.push(command);
	}
	else
	{
		std::cout << "Gagal execute command! Tidak jadi push";
	}
}

void CommandStack::Pop()
{
	if (History.top()->Undo()) {
		RedoStack.push(History.top());
		History.pop();
	}
	else
	{
		std::cout << "Gagal undo command! Tidak jadi pop";
	}
}

void CommandStack::Repush()
{
	if (History.top()->Execute()) {
		History.push(RedoStack.top());
		RedoStack.pop();
	}
	else
	{
		std::cout << "Gagal execute command! Tidak jadi repush";
	}
}
