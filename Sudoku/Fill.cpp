#include "Fill.h"

bool Fill::Execute()
{
	return board->SetValue(colX, rowY, value);
}

bool Fill::Undo()
{
	return board->SetValue(colX, rowY, prevVal);
}
