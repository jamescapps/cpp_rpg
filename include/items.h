#ifndef ITEMS_H
#define ITEMS_H

#include <string>


class Item {
    public:
        std::string type;
        int effectiveness;

    Item(std::string type, int effectiveness);
};
/*
Item Potion("Potion", 10);
Item HiPotion("Hi-Potion", 15);
Item MegaPotion("Mega-Potion", 25);*/

#endif