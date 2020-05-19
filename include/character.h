#ifndef CHARACTER_H
#define CHARACTER_H


class Character {
    private: 
        mutable int attack, defense, magic, heal, stealth, items;
       
    public:
        mutable std::string name;
        mutable int health;

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