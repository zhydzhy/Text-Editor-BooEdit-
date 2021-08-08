// KeypressInteractionReader.cpp
//
// ICS 45C Spring 2021
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "MoveCursorRight.hpp"
#include "Interaction.hpp"
#include "MoveCursorLeft.hpp"
#include "EditorModel.hpp"
#include "MoveCursorHome.hpp"
#include "MoveCursorEnd.hpp"
#include "InsertChar.hpp"
#include "DeleteChar.hpp"
#include "NewLine.hpp"
#include "DeleteLine.hpp"
#include "MoveCursorUp.hpp"
#include "MoveCursorDown.hpp"
// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {

                case 'X':
                {
                    return Interaction::quit();
                }

                case 'O':
                {
                    Command* moveRight = new MoveCursorRight;
                    return Interaction::command(moveRight);
                }
                case 'U':
                {
                    Command* moveLeft = new MoveCursorLeft;
                    return Interaction::command(moveLeft);
                }
                case 'Y':
                {
                    Command* moveHome = new MoveCursorHome;
                    return Interaction::command(moveHome);
                    
                }
                case 'P':
                {
                    Command* moveEnd = new MoveCursorEnd;
                    return Interaction:: command(moveEnd);
                    
                }
                case 'H':
                {
                    Command* deleteChar = new DeleteChar;
                    return Interaction:: command(deleteChar);
                    
                }
                case 'J':
                {
                    Command* newLine = new NewLine;
                    return Interaction:: command(newLine);
                    
                }
                case 'M':
                {
                    Command* newLine = new NewLine;
                    return Interaction:: command(newLine);
                    
                }
                case 'D':
                {
                    Command* deleteLine = new DeleteLine;
                    return Interaction:: command(deleteLine);
                   
                }
                case 'I':
                {
                    Command* moveUp = new MoveCursorUp;
                    return Interaction:: command(moveUp);
                   
                }
                case 'K':
                {
                    Command* moveDown = new MoveCursorDown;
                    return Interaction:: command(moveDown);
                   
                }
                case 'A':
                {
                    return Interaction::redo();
                }

                case 'Z':
                {
                    return Interaction::undo();
                }
            }
        }
        else
        {
            Command* insertCharacter = new InsertChar(keypress.code());
            return Interaction::command(insertCharacter);
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly
            
        }
    }
    
}

