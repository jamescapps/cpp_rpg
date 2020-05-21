#ifndef CHARACTER_H
#define CHARACTER_H


class Character {
    public:
        mutable std::string name;
        mutable int level = 0;
        mutable int health;
        mutable int wins = 0;
        mutable int losses = 0;
        mutable int moves = 0;
        mutable int attack, defense, magic, heal, stealth, items;

        Character(std::string name, int health,  int attack, int defense, 
                        int magic, int heal, int stealth, int items); 

        int Attack() const;
        int Defense() const;
        int Magic() const;
        int Heal() const;
        int Stealth() const;
        int Items() const;
        // Add more functions here for other actions. 
};

#endif