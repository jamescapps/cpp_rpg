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



//Next step is to pull random strings from an array and insert them as challenge1 and challenge 2 values
// Test scenario one
std::string description = "You come to the entrance to a cave. What would you like to do?\n(1) Go inside\n(2) Look around\n(3) Run away";
std::string choice_1 = "You choose to go inside.";
std::string choice_2 = "You choose to look around.";
std::string choice_3 = "You choose to run away";
std::string pre_battle = "You are only a few feet in when a monster comes out of nowhere.\nWhat will you do?\n(1) Fight\n(2)Run away";
std::string choice_4 = "You choose to fight!";
std::string choice_5 = "You choose to run away";

// Test scenario two
std::string description_2 = "A monster approaches you and asks you for a favor. What would you like to do?\n(1) Hear him out\n(2) Tell him to stop where he is\n(3)Run away";
std::string choice_2_1 = "You choose to hear him out.";
std::string choice_2_2 = "You chose to tell him to stop where he is.";
std::string pre_battle_2 =  "He decides you look delicious.\nWhat will you do?\n(1) Fight\n(2)Run away";

Scenario Challenge_1(description, choice_1, choice_2, choice_3, pre_battle, choice_4, choice_5);
Scenario Challenge_2(description_2, choice_2_1, choice_2_2, choice_3, pre_battle_2, choice_4, choice_5);


void Template(const Character& character1, const Scenario& Challenge) {
     while (true) {
        int choice;
        std::cout << Challenge.description << std::endl;
        std::cin >> choice;

        while (true) {
           switch(choice) {
            case 1:
                std::cout << Challenge.choice_1 << std::endl;

                while (true) {
                    std::cout << Challenge.pre_battle << std::endl;

                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> choice;

                    switch(choice) {
                        case 1:
                            std::cout << Challenge.choice_4 << std::endl;
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
                                    Template(character1, Challenge_2);
                                } else if (std::tolower(item_choice) == 'n') {
                                    std::cout << "You go about your way." << std::endl;
                                    //Continue on with game.
                                    Template(character1, Challenge_2);
                                } else {
                                    std::cout << "Please make a valid choice." << std::endl;
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                                }
                            }
                           break;
                        case 2:
                            std::cout << Challenge.choice_5 << std::endl;
                            //Random chance to see if running away is successful.
                            if (rand() % 2 == 0) {
                                std::cout << "Running away was successful!" << std::endl;
                                //continue to adventure page 2
                                Template(character1, Challenge_2);
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
                std::cout << Challenge.choice_2<< std::endl;
                //Get randomly dropped item and save it to inventory then move to next scenario,
                //or move to pre-battle - based on coin flip.
                if (rand() % 2 == 0) {
                    RandomItem();
                    std::cout << "You find a " + RandomItem().type + "!" << std::endl;
                    character1.inventory.push_back(RandomItem().type);
                    save(character1);
                    //Move to next scenario.
                    Template(character1, Challenge_2);
                } else {
                    //Move to pre-battle without receiving item.
                    choice = 1;
                    break;
                }
            case 3:
                std::cout << Challenge.choice_3 << std::endl;
                if (rand() % 2 == 0) {
                    std::cout << "Running away was successful!" << std::endl;
                    //continue to adventure page 2
                    Template(character1, Challenge_2);
                } else {
                    std::cout << "The Monster chases after you! You must fight!" << std::endl;
                    Battle::Initiate(character1, EnemySelection());
                }
            default:
                std::cout << "Please make a valid choice." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          } 
        }
     }
}


void AdventureGame(const Character& character1) {
    std::cout << "Welcome " + character1.name + "! Your adventure awaits..." << std::endl;
     usleep(2000000);
    
    Template(character1, Challenge_1);
}