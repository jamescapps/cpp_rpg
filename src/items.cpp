#include <string>

#include "../include/items.h"


Item::Item(std::string type, int effectiveness) {
    this -> type = type;
    this -> effectiveness = effectiveness;
}
