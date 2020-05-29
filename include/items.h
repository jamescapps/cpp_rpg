#ifndef ITEMS_H
#define ITEMS_H

#include <string>


class Item {
    public:
        std::string type;
        int effectiveness;

    Item(std::string type, int effectiveness);
};

Item RandomItem();


#endif