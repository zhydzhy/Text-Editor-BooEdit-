#ifndef MOVECURSORRIGHT_HPP
#define MOVECURSORRIGHT_HPP

#include "Command.hpp"

class MoveCursorRight : public Command
{
public:

    virtual void execute(EditorModel& editor);
    virtual void undo(EditorModel& editor);

};

#endif //MOVECURSORRIGHT_HPP