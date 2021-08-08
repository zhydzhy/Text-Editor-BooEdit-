#ifndef MOVECURSORLEFT_HPP
#define MOVECURSORLEFT_HPP

#include "Command.hpp"

class MoveCursorLeft : public Command
{
public:
    
    virtual void execute(EditorModel& editor);
    virtual void undo(EditorModel& editor);
};

#endif //MOVECURSORLEFT_HPP