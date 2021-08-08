#ifndef DELETELINE_HPP
#define DELETELINE_HPP

#include "Command.hpp"

class DeleteLine:public Command
{
public:
    virtual void execute(EditorModel& editor);
    virtual void undo(EditorModel& editor);
private:
    int line; //backup to see the original cursor line for undo                  
    int col;  //backup to see the original cursor column for undo
    std:: string backup_text; //backup for the deleted line for undo
};


#endif //DELETELINE_HPP