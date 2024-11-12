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
        float max_weight = 75.0; 
        Inventory inventory;

    public:
        Player() { }
};