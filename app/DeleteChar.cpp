#include "DeleteChar.hpp"

void DeleteChar::execute(EditorModel& editor)
{
    col = editor.cursorColumn();
    line = editor.cursorLine();
    editor.deleteChar();
    if (col != 1)
    {
        c = editor.getBackUpChar();
    }
}

void DeleteChar::undo(EditorModel& editor)
{
    if (editor.cursorLine() != line && col == 1)
    {
        editor.newLine();
    }
    else
    {
        editor.insertChar(c);
    }
}