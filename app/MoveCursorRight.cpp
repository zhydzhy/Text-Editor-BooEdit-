#include "MoveCursorRight.hpp"

void MoveCursorRight::execute(EditorModel& editor)
{
    editor.moveRight();
}

void MoveCursorRight::undo(EditorModel& editor)
{
    editor.moveLeft();
}