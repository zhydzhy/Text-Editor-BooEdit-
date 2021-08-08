#ifndef NEWLINE_HPP
#define NEWLINE_HPP

#include "Command.hpp"

class NewLine: public Command
{
public:
    virtual void execute(EditorModel& editor);
    virtual void undo(EditorModel& editor);
};

#endif //NEWLINE_HPP