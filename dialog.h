#ifndef DIALOG_H
#define DIALOG_H

#include <string>
#include <map>
#include "printing.h"
#include "functional"

using namespace std;

/// @brief Base dialog node class
struct DialogNode
{
    DialogNode(string speaker, string text) : speaker(speaker), text(text) { }

    string speaker;
    string text;

    /// @brief
    virtual void display() = 0;
};

/// @brief Dialog node that can continue to another node
struct DialogNodeContinuous : DialogNode
{
    DialogNodeContinuous(string speaker, string text, DialogNode* next = nullptr) : DialogNode(speaker, text), next(next) { }

    DialogNode* next;

    void display() override
    {
        dialogMessage(speaker, text);

        cin.get(); 

        if (next != NULL)
        {
            next->display();
        }
    }
};

/// @brief Dialog Node with choices
struct DialogNodeChoice : DialogNode
{
    DialogNodeChoice(string speaker, string text, map<string, DialogNode*> options) : DialogNode(speaker, text), options(options) { }

    map<string, DialogNode*> options;

    void display() override
    {
        dialogMessage(speaker, text);

        cin.get(); 

        DialogNode* next = mapOptions(options);

        if (next != NULL)
        {
            next->display();
        }
    }
};

/// @brief Dialog Node that can run an event function
struct DialogNodeEvent : DialogNodeContinuous
{
    DialogNodeEvent(string speaker, string text, function<void()> event, DialogNode* next = nullptr) : DialogNodeContinuous(speaker, text, next), event(event) { }

    function<void()> event;

    void display() override
    {
        dialogMessage(speaker, text);

        cin.get(); 

        event();

        if (next != NULL)
        {
            next->display();
        }
    }

};

#endif