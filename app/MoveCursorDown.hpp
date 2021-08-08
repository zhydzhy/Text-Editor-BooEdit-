#ifndef MOVECURSORDOWN_HPP
#define MOVECURSORDOWN_HPP

#include "Command.hpp"

class MoveCursorDown:public Command
{
public:
    virtual void execute(EditorModel& editor);
    virtual void undo(EditorModel& editor);


private:

    int line; //backup to see the original cursor line for undo
    int col;  //backup to see the original cursor column for undo  
};

#endif //MOVECURSORDOWN_HPP