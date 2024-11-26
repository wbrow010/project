#ifndef PRINTING_H
#define PRINTING_H

#include <string>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

string tolower(string str)
{
    for (char &c : str) {
        c = std::tolower(c);
    }

    return str;
}

/// @brief Ask a message, and get a user input to confirm the action
/// @param message The message to display
/// @return `true` if the user confirms and `false` if the user denies
bool confirmationMessage(string message)
{
    while(true)
    {
        cout << message << " (Y/N): ";
        string input;
        cin >> input;

        input = tolower(input);

        if (input == "y")
            return true;
        else if (input == "n")
            return false;

        cout << "Unknown answer. Try again." << endl;
    }
}

/// @brief Prints a message to the console
/// @param message 
void message(string message)
{
    cout << message << endl;
}

/// @brief Prints a message to the console, in dialog format
/// @param dialog dialog to print
void dialogMessage(string dialog)
{
    cout << "\"" << dialog << "\"" << endl;
}

void errorMessage(string message)
{
    cout << "ERROR: " << message << endl;
}

int options(vector<string> options)
{
    int numberOfOptions = options.size();
    //List the options
    for (int i = 0; i < numberOfOptions; i++)
    {
        cout << options[i] << " " << i << endl;
    }

    while(true)
    {
        int inputChoice;

        cout << "Enter a choice: ";
        cin >> inputChoice;

        if (inputChoice >= 0 && inputChoice < numberOfOptions)
        {
            return inputChoice;
        }

        cout << "Invalid choice, try again." << endl;
    }
}

template <typename T>
T mapOptions(map<string, T> options)
{
    int index = 1;

    map<int, T> indexedOptions;

    for (const auto& [key, value] : options)
    {
        cout << index << ": " << key << '\n';
        indexedOptions[index] = value;
        index++;
    }

    int choice = 0;

    while (true) 
    {
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail() || indexedOptions.find(choice) == indexedOptions.end())
        {
            cout << "Invalid choice, try again." << endl;
        }
        else
        {
            break;
        }
    }

    return indexedOptions[choice];
}

#endif