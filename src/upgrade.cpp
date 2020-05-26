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
                    // Repeat process of getting defense points...
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
    //Level 1
    if (character1.exp > 150) {
        character1.level = 1;
        upgrade_points = 5;
        std::cout << "Congratulations you have achieved level 1!\nYou have 5 points to upgrade attributes with!\nDo you wish to use them now?: (y) (n)" << std::endl;
    }

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
            