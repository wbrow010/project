#include "inventory.h"

struct Stats
{
    /// @brief 
    /// @note Size affects max health, max carry weight, speed
    int size;

    int baseHealth;

    int baseSpeed;

    float baseEncumberedCarryWeight;

    int getMaxHealth()
    {
        return baseHealth + (size * 2);
    }

    Stats(int size, int baseHealth, int baseSpeed, float baseEncumberedCarryWeight) : size(size), baseHealth(baseHealth), baseSpeed(baseSpeed), baseEncumberedCarryWeight(baseEncumberedCarryWeight)
    {

    }
};

class Entity
{  
    protected:
        Stats stats;
        Inventory inventory;
        string name;

    public:
        Entity(Stats stats, string name) : inventory(Inventory()), stats(stats), name(name)
        {

        }

        float getEncumberedCarryWeight()
        {
            return stats.baseEncumberedCarryWeight + (float)stats.size;
        }

        float getMaximumCarryWeight()
        {
            return (getEncumberedCarryWeight() * 2);
        }

        float getSpeed()
        {
            return stats.baseSpeed - (stats.size * 2);
        }

        int getMaxHealth()
        {
            return stats.baseHealth + (stats.size * 2);
        }

        bool addItem(Item item)
        {
            return inventory.addItem(item, getMaximumCarryWeight());
        }

        float getEncumberedFactor()
        {
            return inventory.getEncumberedFactor(getEncumberedCarryWeight(), getMaximumCarryWeight());
        }

        Inventory& getInventory()
        {
            return inventory;
        }
};