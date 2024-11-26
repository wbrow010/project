#include "Items/item.h"
#include <vector>

using namespace std;

class Inventory
{
    private:
        vector<Item> items;
        float encumberedWeight;
        float maximumWeight;
        
    public:
        Inventory(float encumberedWeight, float maximumWeight) : encumberedWeight(encumberedWeight), maximumWeight(maximumWeight)
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

        bool removeItem(string name)
        {
            //Add this
            return false;
        }
        
        /// @brief Gets the weight of all items in the 
        /// @return sum of all item's weights as a `float`
        float getInventoryWeight()
        {
            float weight = 0;

            for (Item& item : items)
            {
                weight += item.getWeight();
            }

            return weight;
        }

        float map(float value, float inLow, float inHigh, float toLow, float toHigh)
        {
            return (value - inLow) * (toHigh - toLow) / (inHigh - inLow) + toLow;
        }

        float lerp(float a, float b, float t)
        {
            return a + (b - a) * t;
        }

        /// @brief Gets a factor based on how encumbered the inventory is
        /// @return Range from `0 - 1` based on how encumbered
        float encumberedFactor()
        {
            float weight = getInventoryWeight();

            if (weight < encumberedWeight) return 0;

            return map(weight, encumberedWeight, maximumWeight, 0, 1);
        }
};