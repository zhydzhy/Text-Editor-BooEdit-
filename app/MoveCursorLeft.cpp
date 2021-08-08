#include "MoveCursorLeft.hpp"

void MoveCursorLeft::execute(EditorModel& editor)
{
    editor.moveLeft();
}

void MoveCursorLeft::undo(EditorModel& editor)
{
    editor.moveRight();
}