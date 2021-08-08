#include "InsertChar.hpp"


InsertChar::InsertChar(char c)
    :c{c}
{
}

void InsertChar::execute(EditorModel& editor)
{
    editor.insertChar(c);
}


void InsertChar::undo(EditorModel& editor)
{
    editor.deleteChar();
}