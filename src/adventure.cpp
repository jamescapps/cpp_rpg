#include <unistd.h>
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>

#include "../include/character.h"
#include "../include/character_selection.h"
#include "../include/battle.h"
#include "../include/continue.h"
#include "../include/adventure.h"
#include "../include/items.h"
#include "../include/save.h"

#include "../include/scenario.h"


void Template(const Character& character1, const Scenario& Challenge_1) {
     while (true) {
        int choice;
        std::cout << Challenge_1.description << std::endl;
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << Challenge_1.choice_1 << std::endl;

                while (true) {
                    std::cout << Challenge_1.pre_battle << std::endl;

                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> choice;

                    switch(choice) {
                        case 1:
                            std::cout << Challenge_1.choice_4 << std::endl;
                            Battle::Initiate(character1, EnemySelection());

                            while(true) {
                                char item_choice;
                                std::cout << "\n\nThe enemy has dropped an item. Would you like to see what it is? (y) (n)" << std::endl;
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                std::cin >> item_choice;

                                if (std::tolower(item_choice) == 'y') {
                                    //Get randomly dropped item and save it to inventory.
                                    RandomItem();
                                    std::cout << "You find a " + RandomItem().type + "!" << std::endl;
                                    character1.inventory.push_back(RandomItem().type);
                                    save(character1);
                                    //Continue on with game.
                                } else if (std::tolower(item_choice) == 'n') {
                                    std::cout << "You go about your way." << std::endl;
                                    //Continue on with game.
                                    //Adventure page 2
                                } else {
                                    std::cout << "Please make a valid choice." << std::endl;
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                                }
                            }
                            
                           break;
                        case 2:
                            std::cout << Challenge_1.choice_5 << std::endl;
                            //Random chance to see if running away is successful.
                            if (rand() % 2 == 0) {
                                std::cout << "Running away was successful!" << std::endl;
                                //continue to adventure page 2
                            } else {
                                std::cout << "The Monster chases after you! You must fight!" << std::endl;
                                Battle::Initiate(character1, EnemySelection());
                            }
                            break;
                        default:
                            std::cout << "Please make a valid choice." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    }
                }
            case 2:
                std::cout << Challenge_1.choice_2<< std::endl;
                //Find an item if you look around.
                //Get randomly dropped item and save it to inventory.
                RandomItem();
                std::cout << "You find a " + RandomItem().type + "!" << std::endl;
                character1.inventory.push_back(RandomItem().type);
                save(character1);
                
                break;
            case 3:
                std::cout << Challenge_1.choice_3 << std::endl;
                break;
            default:
                std::cout << "Please make a valid choice." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
     }

}

//Eventually could create random scenarios.

void AdventureGame(const Character& character1) {
    std::cout << "Welcome " + character1.name + "! Your adventure awaits..." << std::endl;
     usleep(2000000);
    
    std::string description = "You come to the entrance to a cave. What would you like to do?\n(1) Go inside\n(2) Look around\n(3) Run away";
    std::string choice_1 = "You choose to go inside.";
    std::string choice_2 = "You choose to look around.";
    std::string choice_3 = "You choose to run away";
    std::string pre_battle = "You are only a few feet in when a monster comes out of nowhere.\nWhat will you do?\n(1) Fight\n(2)Run away";
    std::string choice_4 = "You choose to fight!";
    std::string choice_5 = "You choose to run away";
    
    Scenario Challenge_1(description, choice_1, choice_2, choice_3, pre_battle, choice_4, choice_5);

    Template(character1, Challenge_1);
}

