#include <iostream> 

#include "../include/character.h"


//Character will have 50 available points, every category must have at
//least 1 point.
Character::Character(std::string name, int level, int wins, int losses, int health,  int attack, int defense, 
                int magic, int heal, int stealth, int items, int exp) {
    this -> name = name;
    this -> level = level;
    this -> wins = wins;
    this -> losses = losses;
    this -> health = health;
    this -> attack = attack;
    this -> defense = defense;
    this -> magic = magic; 
    this -> heal = heal;
    this -> stealth = stealth;
    this -> items = items;
    this -> exp = exp;
}

int Character::Attack() const {
    return std::rand() % this -> attack;
}

int Character::Defense() const {
    return std::rand() % this -> defense;
}

int Character::Magic() const {
    return std::rand() % this -> magic;
}

int Character::Heal() const {
    return std::rand() % this -> heal;
}

int Character::Stealth() const {
    return std::rand() % this -> stealth;
}

int Character::Items() const {
    return std::rand() % this -> items;
}
// Add more functions here for other actions. 