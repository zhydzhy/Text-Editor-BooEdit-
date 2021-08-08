#ifndef MOVECURSORUP_HPP
#define MOVECURSORUP_HPP

#include "Command.hpp"

class MoveCursorUp:public Command
{
public:
    virtual void execute(EditorModel& editor);
    virtual void undo(EditorModel& editor);


private:

    int line; //backup to see the original cursor line for undo
    int col;  //backup to see the original cursor column for undo
};







#endif //MOVECURSORUP_HPP