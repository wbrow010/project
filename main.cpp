#include <iostream>
#include "player.h"
#include "dialog.h"
#include <cstring>

#include "printing.h"

using namespace std;

void test()
{
    cout << "BLASHAHSJDHJASHDJDHWKJFWA" << endl;
}

DialogNodeContinuous dialog = 
{
    "This is a dialog test.",
    new DialogNodeContinuous
    {
        "This is the next part of the dialog.",
        new DialogNodeChoice
        {
            "This is a choice node!",
            {
                {
                    "Choice One.",
                    new DialogNodeContinuous
                    {
                        "You chose choice one.",
                        new DialogNodeEvent
                        {
                            "RUNNING AN EVENT",
                            test
                        }
                    }
                },
                {
                    "Choice Two.",
                    new DialogNodeContinuous
                    {
                        "You chose choice two."
                    }
                }
            }
        }
    }
};

int main()
{

    bool quit = false;
    Player player;

    message("THE GAME STARTS");

    dialog.display();

    while (!quit)
    {
        // Get the user input
        string input;
        cin >> input;

        
    }

    return 0;
}