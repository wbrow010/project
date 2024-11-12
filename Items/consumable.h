#include "item.h"

class Consumable : public Item
{
    private:
        int usesLeft;

        /// @brief The action to perform when the consumable is used
        void consumableAction()
        {

        }

    public:
        Consumable(string name, float weight) : Item(name, weight)
        {

        }

        /// @brief Uses the consumable and depletes one use
        void useConsumable()
        {
            if (!usedUp())
            {
                consumableAction();
                usesLeft--;
            }
            else
            {
                std::cout << "Item cannot be used any more!" << std::endl;
            }
        }

        /// @brief Checks if the item is used up
        /// @return `true` if there are 1 or more uses, `false` if there are 0 or less
        bool usedUp()
        {
            if (usesLeft <= 0) return true;
            return false;
        }

        int getUses()
        {
            return usesLeft;
        }
};