#include <string>
#include <map>
#include "printing.h"
#include "functional"

using namespace std;

struct DialogNode
{
    DialogNode(string text) : text(text) { }

    string text;

    virtual void display() = 0;
};

/// @brief Dialog node that can continue to another node
struct DialogNodeContinuous : DialogNode
{
    DialogNodeContinuous(string text, DialogNode* next = nullptr) : DialogNode(text), next(next) { }

    DialogNode* next;

    void display() override
    {
        dialogMessage(text);

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
    DialogNodeChoice(string text, map<string, DialogNode*> options) : DialogNode(text), options(options) { }

    map<string, DialogNode*> options;

    void display() override
    {
        dialogMessage(text);

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
    DialogNodeEvent(string text, function<void()> event, DialogNode* next = nullptr) : DialogNodeContinuous(text, next), event(event) { }

    function<void()> event;

    void display() override
    {
        dialogMessage(text);

        cin.get(); 

        event();

        if (next != NULL)
        {
            next->display();
        }
    }

};