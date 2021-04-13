#pragma once
class Command
{
public:
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

