#include <iostream> 
#include <unistd.h>
#include <math.h> 

#include "../include/character.h"
#include "../include/battle.h"
#include "../include/weapon.h"


void Battle::Initiate(const Character& character1, const Character& character2) {
    std::cout << "\n\n" + character1.name + " encounters " + character2.name + "!\n"<< std::endl;
    while (true) {
        if (Battle::AttackResult(character1, character2).compare("End of battle!") == 0) {
            std::cout << "End of battle! \n";
            break;
        }
    }
}

//Battle logic
std::string Battle::AttackResult(const Character& character1, const Character& character2) {
    int char1_attack = character1.Attack();
    int char2_attack = character2.Attack();

    int char1_defense = character1.Defense();
    int char2_defense = character1.Defense();
    
    int char1_magic = character1.Magic();
    int char2_magic = character2.Magic();

    int char1_heal = character1.Heal();
    int char2_heal = character2.Heal();

    int char1_stealth = character1.Stealth();
    int char2_stealth = character2.Stealth();

    int char1_items = character1.Items();
    int char2_items = character2.Items();

    //Add more here later...

    // Attack choices
    int action;
    std::cout << "What action will you take?: \n(1) Attack\n(2) Defend\n(3) Use Magic\n(4) Heal\n(5) Steal\n(6) Use Item" << std::endl;
    std::cin >> action;

    //Hero actions
    switch(action) {
        case 1: {
            int char2_damage = abs(ceil(char1_attack - char2_defense));
            character2.health = character2.health - char2_damage;
            std::cout << character1.name + " attacks " + character2.name + " and deals " + std::to_string(char2_damage) + " damage."<< std::endl;
            usleep(2000000);
            break; 
        }
        case 2: {
            char1_defense = char1_defense + .5;
            std::cout << character1.name + " takes a defensive position." << std::endl;
            usleep(2000000);
            break;
        }
        case 3: {
            int char2_damage = abs(ceil(char1_magic - char2_defense));
            character2.health = character2.health - char2_damage;
            std::cout << character1.name + " casts a spell on " + character2.name + " and deals " + std::to_string(char2_damage) + " damage." << std::endl;
            usleep(2000000);
            break;
        }
        case 4: {
            character1.health = character1.health + char1_heal;
            std::cout << character1.name + " heals and receives " + std::to_string(char1_heal) + " health." << std::endl;
            break;
        }
        case 5: {
            //Not sure how to handle steal yet.
            break;
        }
        case 6: {
            //Not sure how to handle items yet.
            break;
        }
        default:
            std::cout << "Please make a valid selection." << std::endl;

    }

    //Should randomize who attacks first and as soon as damage is zero player should die.
    //Monster Attack
    int char1_damage = abs(ceil(char2_attack - char1_defense));
    character1.health = character1.health - char1_damage;
    std::cout << character2.name + " attacks " + character1.name + " and deals " + std::to_string(char1_damage) + " damage." << std::endl;
    usleep(2000000);

    //Check result of attacks.
    //Make sure health stops at zero.
    character1.health = character1.health < 0 ? 0 : character1.health;
    character2.health = character2.health < 0 ? 0 : character2.health;
    //Check for a victor.
    if (character1.health == 0) {
        std::cout << character1.name + " has died!\n" + character2.name + " WINS the battle!" << std::endl;
        return "End of battle!";
    } else if (character2.health == 0) {
        std::cout << character2.name + " has died.\n" + character1.name + " WINS the battle!" <<std::endl;
        return "End of battle!";
    } else {
        std::cout << "\t" + character1.name + " health: " + std::to_string(character1.health) + "\n\t" + character2.name + " health: " + std::to_string(character2.health) <<std::endl;
        //Reset defense so that extra defense points do not carry over to the next turn.
        char1_defense = character1.Defense();
    }
    return "End of turn!";
}
