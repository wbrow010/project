#include <iostream>
#include "player.h"

using namespace std;
int main()
{
    Player player;

    Inventory& playerInventory = player.getInventory();

    playerInventory.addItem(Item("big item", 17.5f));
    float playerEncumberedFactor = playerInventory.encumberedFactor();

    cout << playerEncumberedFactor << endl; 
    
    cout << player.getInventoryWeight() << endl;
    return 0;
}