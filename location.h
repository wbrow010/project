#include "printing.h"

using namespace std;

enum Temperature
{
    HOT,
    NEUTRAL,
    COLD
};

class Location
{
    private:
        string name = "Location";
        string enterMessage = "Default location message.";
        Temperature temperature;

    public:
        Location();

        Location(string name, string enterMessage, Temperature temperature = NEUTRAL) : name(name), enterMessage(enterMessage), temperature(temperature)
        {
            
        }

        void displayEnterMessage()
        {
            message(enterMessage);
        }
};