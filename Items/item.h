#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

using namespace std;

class Item
{
    private:
        string name;
        float weight;

    public:
        Item(string name, float weight) : name(name), weight(weight) { }

        /// @brief Gets the weight of the item
        /// @return the weight as a `float`
        float getWeight() const
        {
            return weight;
        }

        string getName() const
        {
            return name;
        }
};

#endif