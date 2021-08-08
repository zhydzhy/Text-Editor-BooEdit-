#ifndef DELETECHAR_HPP
#define DELETECHAR_HPP

#include "Command.hpp"

class DeleteChar:public Command
{
public:
    virtual void execute(EditorModel& editor);
    virtual void undo(EditorModel& editor);

private:
    int line;   //backup to see the original cursor line for undo
    int col;    //backup to see the original cursor column for undo
    char c;     //backup to see the original character for undo
};



#endif //DELETECHAR_HPP