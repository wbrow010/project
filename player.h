#include <string>
#include <iostream>
#include "inventory.h"

using namespace std;

class Player
{
    private:
        string name;
        int number;
        int damage_calc;
        Inventory inventory;

    public:
        Player() { }
};