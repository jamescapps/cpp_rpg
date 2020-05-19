#ifndef WEAPON_H
#define WEAPON_H

#include <string>


class Weapon {
    //Not using yet... but eventually will play into attack formula.
    private:
        int damage_amt;
        int stability;

    public:
        std::string type;

    Weapon(std::string type, int damage_amt, int stability);
};

#endif