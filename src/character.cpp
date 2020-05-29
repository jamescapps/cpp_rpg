#include <iostream> 

#include "../include/character.h"


//Character will have 50 available points, every category must have at
//least 1 point.
Character::Character(std::string name, int level, int wins, int losses, int health,  int attack, int defense, 
                int magic, int heal, int items, int exp, std::vector<std::string> inventory) {
    this -> name = name;
    this -> level = level;
    this -> wins = wins;
    this -> losses = losses;
    this -> health = health;
    this -> attack = attack;
    this -> defense = defense;
    this -> magic = magic; 
    this -> heal = heal;
    this -> items = items;
    this -> exp = exp;
    this -> inventory = inventory;
}


//Need to adjust these to be more accurate and consistent.
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

int Character::Items() const {
    return std::rand() % this -> items;
}
// Add more functions here for other actions. 