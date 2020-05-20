#include <iostream> 
#include <unistd.h>
#include <vector> 

#include "../include/character_selection.h"
#include "../include/battle.h"
#include "../include/weapon.h"


//Get and check value for custom character.
void CustomChecks(const std::string& name, int& attribute, int& points_left, int&position) {
            while (true) {
                std::cout << "How many points would you like to give to the " + name + " category?";
                std::cin >> attribute;

                //Make sure an integer is input.
                while(!std::cin) {
                    std::cout << "Please enter an integer: ";
                    std::cin.clear();
                    std::cin.ignore();
                    std::cin >> attribute;
                }

                //Make sure number is within parameters.
                if (attribute == 0 || attribute > (points_left - position)) {
                    std::cout << "Value must be between 1 and " + std::to_string(points_left - position) << std::endl;
                    // Repeat process of getting defense points...
                } else {
                    points_left = points_left - attribute;
                    if (points_left != 0) {
                        std::cout << "You have " + std::to_string(points_left) + " points left." << std::endl;
                    }
                    position--;
                    break;
                }
        }
 }

Character CustomCharacter() {
    int points_left = 50;
    int position = 5;

    std::cout << "What is your character's name?: ";
    std::cin.ignore();
    std::getline(std::cin,char_name);
    
    std::cout <<"You have 50 ability points. Use them wisely...Every category must have at least 1 point...\n";
    usleep(1000000);
    //Run function to check and aquire input for each category.
    CustomChecks("attack", char_attack, points_left, position);
    CustomChecks("defense", char_defense, points_left, position);
    CustomChecks("magic", char_magic, points_left, position);
    CustomChecks("heal", char_heal, points_left, position);
    CustomChecks("stealth", char_stealth, points_left, position);
    CustomChecks("items", char_items, points_left, position);

    Character hero(char_name, char_health, char_attack, char_defense, char_magic, char_heal, char_stealth, char_items);
    return hero;
}

Character HeroSelection() {
    int selection;

    std::cout << "What character would you like to be?:\n(1) Warrior\n(2) Tank\n(3) Wizard\n(4) Healer\n(5) Thief\n(6) Custom Character\n";
    std::cin >> selection;

    //Match selection to category and apply attributes.
    switch(selection) {
        case 1: {
            Character hero("Warrior", char_health, 30, 10, 1, 1, 30, 7);
            return hero;
        }
        case 2: {
            Character hero("Tank", char_health, 10, 30, 1, 1, 1, 7);
            return hero;
        }
        case 3: {
            Character hero("Wizard", char_health, 1, 5, 30, 10, 1, 3);
            return hero;
        }
        case 4: {
            Character hero("Healer", char_health, 1, 1, 5, 30, 4, 9);
            return hero;
        }
        case 5: {
            Character hero("Thief", char_health, 5, 3, 1, 1, 30, 10);
            return hero;
        }
        case 6: {
            return CustomCharacter();
        }   
        default:
            std::cout << "Please make a valid selection!\n";
            HeroSelection();
    }
        //Line seems to only be necessary to avoid compiling error.
        Character hero(char_name, char_health, char_attack, char_defense, char_magic, char_heal, char_stealth, char_items);
        return hero; 
}

Character EnemySelection() {
    //Get a random enemy
    std::string enemies[5] = {"Demon", "Orc", "Giant Spider", "Troll", "Dragon"};
    std::string enemy;
    int rand_index = rand() % 5;
    enemy = enemies[rand_index];
          
    //Check which enemy and apply attributes.
    if (enemy == "Demon") {
        Character monster("Demon", 200, 15, 5, 10, 1, 1, 1);
        return monster;
     } else if (enemy == "Orc") {
        Character monster("Orc", 50, 5, 2, 2, 1, 1, 1);
        return monster;
     } else if (enemy == "Giant Spider") {
        Character monster("Giant Spider", 100, 10, 5, 1, 1, 1, 1);
        return monster;
     } else if (enemy == "Troll") {
        Character monster("Troll", 20, 3, 3, 1, 1, 1, 1);
        return monster;
     } else if (enemy == "Dragon") {
        Character monster("Dragon", 250, 20, 7, 5, 1, 1, 1);
        return monster;
     } else {
         std::cout << "Something went wrong..." << std::endl;
     }
     //Line seems to only be necessary to avoid compiling warning.
     Character monster(char_name, char_health, char_attack, char_defense, char_magic, char_heal, char_stealth, char_items);
     return monster;
}