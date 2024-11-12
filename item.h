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
};