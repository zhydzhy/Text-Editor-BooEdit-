#ifndef INSERTCHAR_HPP
#define INSERTCHAR_HPP

#include "Command.hpp"

class InsertChar : public Command
{

public: 
    InsertChar(char c); // Stores user input
    virtual void execute(EditorModel& editor);
    virtual void undo(EditorModel& editor);

private:

    char c;

};


#endif //INSERTCHAR_HPP