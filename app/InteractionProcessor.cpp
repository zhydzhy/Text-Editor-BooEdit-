// InteractionProcessor.cpp
//
// ICS 45C Spring 2021
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"
#include <vector>

void clearVector(std::vector<Command*>& v)
{
    for (int i = 0; i < v.size(); i ++)
    {
        delete v[i];
    }
    v.clear();
}
// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.        

void InteractionProcessor::run()
{
    std:: vector<Command*> undoList;
    std:: vector<Command*> redoList;

    view.refresh();

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if (!undoList.empty())
            {
                try
                {
                    undoList.back()->undo(model);
                    model.clearErrorMessage();
                    redoList.push_back(undoList.back());
                    undoList.pop_back();
                }
                catch (EditorException& e)
                {
                    model.setErrorMessage(e.getReason());
                }
            }
            
            view.refresh();
        }
        else if (interaction.type() == InteractionType::redo)
        {
            if (!redoList.empty())
            {
                try
                {
                    redoList.back()->execute(model);
                    model.clearErrorMessage();
                    undoList.push_back(redoList.back());
                    redoList.pop_back();
                }
                catch(EditorException& e)
                {
                    model.setErrorMessage(e.getReason());
                }
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::command)
        {
            
            try
            {
                interaction.command()->execute(model);
                clearVector(redoList);
                model.clearErrorMessage();
                undoList.push_back(interaction.command());
                
            }
            catch (EditorException& e)
            {
                delete interaction.command();
                model.setErrorMessage(e.getReason());
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
            
        }

        
    }
    clearVector(redoList);
    clearVector(undoList);
}

