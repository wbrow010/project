#include <string>
#include <iostream>
#include "inventory.h"
#include "entity.h"

using namespace std;

class Player : public Entity
{
    private:

    public:
        Player() : Entity(Stats{0, 0, 0, 0}, "DefaultPlayer") {}
    
        Player(Stats stats, string name) : Entity(stats, name)
        {

        }

        void displayInventory()
        {
            getInventory().displayContents();
        }

        bool addItem(Item item)
        {
            if (Entity::addItem(item))
            {
                cout << name << " added item: " << item.getName() << endl;
                return true;
            }
            else
            {
                cout << name << " could not add item: " << item.getName() << ". Inventory is full or too heavy!" << endl;
                return false;
            }
        }
};