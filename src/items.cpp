#include <string>
#include <vector>

#include "../include/items.h"


Item::Item(std::string type, int effectiveness) {
    this -> type = type;
    this -> effectiveness = effectiveness;
}


Item Potion("Potion", 10);
Item HiPotion("Hi-Potion", 15);
Item MegaPotion("Mega-Potion", 25);

Item RandomItem() {
    std::vector<Item> all_items;

    all_items.push_back(Potion);
    all_items.push_back(HiPotion);
    all_items.push_back(MegaPotion);

    int random_index = std::rand() % all_items.size();

    return all_items[random_index];
}