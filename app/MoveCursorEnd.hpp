#ifndef MOVECURSOREND_HPP
#define MOVECURSOREND_HPP

#include "Command.hpp"

class MoveCursorEnd:public Command
{
public:

    virtual void execute(EditorModel& editor);
    virtual void undo(EditorModel& editor);

private:
    int line; //backup to see the original cursor line for undo
    int col;  //backup to see the original cursor column for undo
};

#endif //MOVECURSOREND_HPP
