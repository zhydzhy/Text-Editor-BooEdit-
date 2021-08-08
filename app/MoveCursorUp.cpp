#include "MoveCursorUp.hpp"

void MoveCursorUp::execute(EditorModel& editor)
{
    line = editor.cursorLine();
    col = editor.cursorColumn();

    editor.moveUp();

}

void MoveCursorUp::undo(EditorModel& editor)
{
    editor.moveBack(line, col);
}