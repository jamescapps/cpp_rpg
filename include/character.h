#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>


class Character {
    public:
        mutable std::string name;
        mutable int level = 0;
        mutable int health;
        mutable int wins = 0;
        mutable int losses = 0;
        mutable int moves = 0;
        mutable int exp = 0;
        mutable int attack, defense, magic, heal, stealth, items;
        mutable std::vector<std::string> inventory = {};

        Character(std::string name, int level, int wins, int losses, int health,  int attack, int defense, 
                        int magic, int heal, int items, int exp, std::vector<std::string> inventory); 

        int Attack() const;
        int Defense() const;
        int Magic() const;
        int Heal() const;
        int Items() const;
        // Add more functions here for other actions. 
};

#endif