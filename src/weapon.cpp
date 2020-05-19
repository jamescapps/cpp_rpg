#include "../include/weapon.h"


Weapon::Weapon(std::string type, int damage_amt, int stability) {
    this -> type = type;
    this -> damage_amt = damage_amt;
    this -> stability = stability;
}
