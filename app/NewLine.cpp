#include "NewLine.hpp"

void NewLine::execute(EditorModel& editor)
{
    editor.newLine();
}

void NewLine:: undo(EditorModel& editor)
{
    editor.deleteChar();
}