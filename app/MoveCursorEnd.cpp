#include "MoveCursorEnd.hpp"

void MoveCursorEnd::execute(EditorModel& editor)
{
    col = editor.cursorColumn();
    line = editor.cursorLine();
    editor.moveEnd();
}


void MoveCursorEnd::undo(EditorModel& editor)
{
    editor.moveBack(line, col);
}