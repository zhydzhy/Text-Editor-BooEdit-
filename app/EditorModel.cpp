// EditorModel.cpp
//
// ICS 45C Spring 2021
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"


EditorModel::EditorModel()
    :cursor_line{1}, cursor_col{1},text{""},error_message{""}
{
}


int EditorModel::cursorLine() const
{
    return cursor_line;
}


int EditorModel::cursorColumn() const
{
    return cursor_col;
}


int EditorModel::lineCount() const
{
    return text.size();
}


const std::string& EditorModel::line(int lineNumber) const
{
    return text.at(lineNumber-1);
}


const std::string& EditorModel::currentErrorMessage() const
{
    return error_message;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    error_message = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    error_message = "";
}

void EditorModel::moveRight()
{
    if (cursor_line < lineCount())
    {
        cursor_col = 1;
        cursor_line +=1;
    }
    else if (cursor_col < text.at(cursor_line-1).length()+1)
    {
        cursor_col += 1;
    }
    else
    {
        throw EditorException("Already at end");
    }
}

void EditorModel:: moveLeft()
{
    if (cursor_col > 1)
    {
        cursor_col -= 1;
    }
    else if (cursor_line > 1)
    {
        cursor_line -= 1;
        cursor_col = text.at(cursor_line-1).length()+1;
    }
    else
    {
        throw EditorException("Already at beginning");
    }
}


void EditorModel:: moveHome()
{
    cursor_col = 1;
}

void EditorModel:: moveEnd()
{
    cursor_col = text.at(cursor_line-1).length()+1;
}


void EditorModel:: moveBack(int line, int col)
{
    cursor_line = line;
    cursor_col = col;
}

void EditorModel::insertChar(char c)
{
    text.at(cursor_line-1) = text.at(cursor_line-1).insert(cursor_col-1, 1, c);

    cursor_col++;
}

void EditorModel::deleteChar()
{
    if(cursor_col == 1 && cursor_line == 1)
    {
        throw EditorException("Already at beginning");
    }
    else if (cursor_col == 1)
    {
        cursor_col = text.at(cursor_line-2).length()+1;
        text.at(cursor_line-2) += text.at(cursor_line -1);
        text.erase(text.begin()+cursor_line -1);
        cursor_line --;
    }
    else
    {
        backup_char = text.at(cursor_line-1).at(cursor_col -2);
        text.at(cursor_line-1) = text.at(cursor_line-1).erase(cursor_col-2,1);
        cursor_col--;
    }
}

char EditorModel::getBackUpChar()
{
    return backup_char;
}

void EditorModel::newLine()
{
    std:: string temp = text.at(cursor_line-1).substr(cursor_col-1);
    text.at(cursor_line-1) = text.at(cursor_line-1).substr(0,cursor_col -1);
    text.insert(text.begin() + cursor_line, temp);

    cursor_line ++;
    cursor_col = 1;
}

void EditorModel:: deleteLine()
{
    backup_str = text.at(cursor_line-1);
    if (backup_str == "" && cursor_col == 1 && cursor_line == 1)
    {
        throw EditorException("Already empty");
    }
    else if (lineCount() == 1)
    {
        text.push_back("");
        text.erase(text.begin() + cursor_line -1);
        cursor_line = 1;
        cursor_col = 1;
    }
    else
    {
        text.erase(text.begin()+cursor_line-1);

        if (cursor_line > 1)
        {
            cursor_line --;
        }
        else {cursor_line = 1;}

        if (cursor_col > text.at(cursor_line-1).length()+1)
        {
            cursor_col = text.at(cursor_line-1).length()+1;
        }
    }
}

std::string EditorModel::getBackUpStr()
{
    return backup_str;
}

void EditorModel:: insertLine(std::string& line)
{
    if (cursor_line == 1){text.pop_back();}
    text.insert(text.begin() + cursor_line- 1, line);
}

void EditorModel:: moveUp()
{
    if (cursor_line > 1)
    {
        cursor_line --;
        if(cursor_col > text.at(cursor_line - 1).length()+1)
        {
            cursor_col = text.at(cursor_line-1).length()+1;
        }
    }
    else
    {
        throw EditorException("Already at top");
    }
}

void EditorModel:: moveDown()
{
    if (cursor_line < lineCount())
    {
        cursor_line ++;
        if(cursor_col > text.at(cursor_line - 1).length()+1)
        {
            cursor_col = text.at(cursor_line-1).length()+1;
        }
    }
    else
    {
        throw EditorException("Already at bottom");
    }
}