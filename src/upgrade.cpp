#include <iostream> 
#include <unistd.h>
#include <math.h>
#include <limits>
#include <fstream> 

#include "../include/character.h"
#include "../include/character_selection.h"
#include "../include/battle.h"
#include "../include/weapon.h"
#include "../include/upgrade.h"


void upgrade(const std::string& name, int& attribute, int& points_left) {
    while (true) {
                int points;
                std::cout << "How many points would you like to give to the " + name + " category?";
                std::cin >> points;

                //Make sure an integer is input.
                while(!std::cin) {
                    std::cout << "Please enter an integer: ";
                    std::cin.clear();
                    std::cin.ignore();
                    std::cin >> points;
                }
                //Make sure number is within parameters.
                if (points > points_left) {
                    std::cout << "Value must be between 0 and " + std::to_string(points_left) << std::endl;
                } else {
                    points_left = points_left - points;
                    attribute += points;
                    if (points_left != 0) {
                        std::cout << "You have " + std::to_string(points_left) + " points left." << std::endl;
                    }
                    break;
                }
    }    
}

void check_for_upgrade(const Character& character1) {
    int upgrade_points;

    if (character1.level == 0 && character1.exp > 150) {
        character1.level++;
        upgrade_points = 5;
        std::cout << "Congratulations you have achieved level 1!\nYou have 5 points to upgrade attributes with!\nDo you wish to use them now?: (y) (n)" << std::endl;
    } else if (character1.level == 1 && character1.exp > 350) {
        character1.level++;
        upgrade_points = 7;
        std::cout << "Congratulations you have achieved level 2!\nYou have 7 points to upgrade attributes with!\nDo you wish to use them now?: (y) (n)" << std::endl;
    } else if (character1.level == 2 && character1.exp > 600) {
        character1.level++;
        upgrade_points = 10;
        std::cout << "Congratulations you have achieved level 3!\nYou have 10 points to upgrade attributes with!\nDo you wish to use them now?: (y) (n)" << std::endl;
    } else if (character1.level == 3 && character1.exp > 950) {
        character1.level++;
        upgrade_points = 12;
        std::cout << "Congratulations you have achieved level 4!\nYou have 12 points to upgrade attributes with!\nDo you wish to use them now?: (y) (n)" << std::endl;
    } else {
        return;
    }

    //Can add more levels later or find a reusable way to do it so you can level infinitely.

    while (true) {
        char upgrade_response;
        std::cin >> upgrade_response;
        if (std::tolower(upgrade_response) == 'y') {
            upgrade("attack", character1.attack, upgrade_points);
            upgrade("defense", character1.defense, upgrade_points);
            upgrade("magic", character1.magic, upgrade_points);
            upgrade("heal", character1.heal, upgrade_points);
            upgrade("stealth", character1.stealth, upgrade_points);
            upgrade("items", character1.items, upgrade_points);
            break;

        } else if (std::tolower(upgrade_response) == 'n') {
            std::cout << "Your experience will be saved and you can upgrade later!" <<std::endl;
            break;
        } else {
            std::cout << "Please make a valid selection." << std::endl;
        } 
    }
}
            