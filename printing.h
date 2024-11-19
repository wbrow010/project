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
void dialog(string dialog)
{
    cout << "\"" << message << "\"" << endl;
}

int options(vector<string> options)
{
    for (int i = 0; i < options.size(); i++)
    {
        cout << options[i] << " " << i << endl;
    }

    return 0; // change this to return an input number
}