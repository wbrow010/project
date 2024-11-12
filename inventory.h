#include "Items/item.h"
#include <vector>

using namespace std;

class Inventory
{
    private:
        vector<Item> items;
        float maximumWeight;
        
    public:
        Inventory(float maximumWeight) : maximumWeight(maximumWeight)
        {

        }

        /// @brief Adds an item to the inventory
        /// @param item item to add to the inventory
        /// @return `true` if item could be added without exceeding maximum weight, `false` if not
        bool addItem(Item item)
        {
            if (item.getWeight() + getInventoryWeight() <= maximumWeight)
            {
                items.push_back(item);
                return true;
            }

            return false;
        }
        
        /// @brief Gets the weight of all items in the 
        /// @return sum of all item's weights as a `float`
        float getInventoryWeight()
        {
            float weight = 0;

            for (Item item : items)
            {
                weight += item.getWeight();
            }
        }
};