#include <string>
#include <map>
#include "printing.h"

using namespace std;

struct DialogNode
{
    string text;
    map<string, DialogNode*> options;

    display()
    {
        
    }
};

struct DialogNodeEvent : public DialogNode
{

}

DialogNode* exampleDialog = new DialogNode
{
    "This is a test of the DialogNode system",
    {
        {
            "I'm option one, and should be represented with the proper number.", 
            new DialogNode
            {
                "Do you want to see what I have to sell?",
                {
                    {
                        "Yes",
                        new DialogNode { "Okay, Opening Shop Window" }
                    },
                    {
                        "No",
                        new DialogNode { "Okay, Goodbye" }
                    }
                }
            }
        },

        {
            "I'm option two, and should be represented with the proper number.",
            new DialogNode
            {
                "The dialog system should be able to execute events",
                {
                    {
                        "I want treasure", new DialogNode{"You encounter a wild animal!"}
                    },
                    {
                        "End Conversation", new DialogNode{"You encounter a wild animal!"}
                    }
                }
            }
        }
    }
}