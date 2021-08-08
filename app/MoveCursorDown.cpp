#include "MoveCursorDown.hpp"

void MoveCursorDown::execute(EditorModel& editor)
{
    line = editor.cursorLine();
    col = editor.cursorColumn();

    editor.moveDown();

}

void MoveCursorDown::undo(EditorModel& editor)
{
    editor.moveBack(line, col);
}