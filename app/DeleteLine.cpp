#include "DeleteLine.hpp"


void DeleteLine:: execute(EditorModel& editor)
{
    line = editor.cursorLine();
    col = editor.cursorColumn();
    editor.deleteLine();
    backup_text = editor.getBackUpStr();
}


void DeleteLine:: undo(EditorModel& editor)
{
    editor.moveBack(line, col);
    editor.insertLine(backup_text);
    
}