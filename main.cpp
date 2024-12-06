#include <iostream>
#include "player.h"
#include "dialog.h"
#include <cstring>
#include <sstream>

#include "printing.h"

using namespace std;

Player player(Stats(5, 100, 100, 40), "Player1");

void test()
{
    player.addItem(Item("Potion", 40.0f));
}

DialogNodeContinuous dialog = 
{
    "TestNPC",
    "This is a dialog test.",
    new DialogNodeContinuous
    {
        "TestNPC",
        "This is the next part of the dialog.",
        new DialogNodeChoice
        {
            "TestNPC",
            "This is a choice node!",
            {
                {
                    "I want a potion.",
                    new DialogNodeContinuous
                    {
                        "TestNPC",
                        "Okay, let me see if I have one.",
                        new DialogNodeEvent
                        {
                            "TestNPC",
                            "I do, here you go.",
                            test
                        }
                    }
                },
                {
                    "Bye.",
                    new DialogNodeContinuous
                    {
                        "TestNPC",
                        "Goodbye."
                    }
                }
            }
        }
    }
};

vector<string> splitWords(string str) 
{
    vector<string> words;
    stringstream ss(str);
    string word;
    
    while (ss >> word) {
        words.push_back(word);
    }
    
    return words;
}

vector<string> getInput()
{
    string input;
    cout << "> ";
    getline(cin, input);

    return splitWords(input);
}

int main()
{

    bool quit = false;

    player.addItem(Item("Sword", 10));
    player.addItem(Item("Shield", 15));

    while (!quit)
    {
        // Vector to store the split words
        vector<string> words = getInput();

        if (words.empty()) { continue; } 

        if (words[0] == "inventory")
        {
            player.displayInventory();
        }
        else if (words[0] == "talk")
        {
            dialog.display();
        }
        else if (words[0] == "drop")
        {
            string itemName = words[1];  // The second word is the item name
            player.getInventory().removeItem(itemName);
        }
        else if (words[0] == "quit")
        {
            quit = true;
        }
        else
        {
            cout << "Unknown command." << endl;
        }

        if (player.getEncumberedFactor() > 0 )
        {
            message("You are over-encumbered! Drop some items to recover!");
        }

    }

    return 0;
}