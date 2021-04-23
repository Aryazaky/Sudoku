#include "Delete.h"

bool Delete::Execute()
{
	deletedVal = board->GetValue(colX, rowY);
	return board->SetValue(colX, rowY, 0);
}

bool Delete::Undo()
{
	return board->SetValue(colX, rowY, deletedVal);
}
