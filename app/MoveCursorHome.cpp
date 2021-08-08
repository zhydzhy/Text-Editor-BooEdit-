#include "MoveCursorHome.hpp"

void MoveCursorHome::execute(EditorModel& editor)
{
    col = editor.cursorColumn();
    line = editor.cursorLine();
    editor.moveHome();
}

void MoveCursorHome:: undo(EditorModel& editor)
{
    editor.moveBack(line, col);
}