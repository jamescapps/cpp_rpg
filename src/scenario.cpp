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


Scenario::Scenario(const std::string& description, 
                   const std::string& choice_1, 
                   const std::string& choice_2, 
                   const std::string& choice_3, 
                   const std::string& choice_4, 
                   const std::string& choice_5,
                   const std::string& choice_6) {

                       this -> description = description;
                       this -> choice_1 = choice_1;
                       this -> choice_2 = choice_2;
                       this -> choice_3 = choice_3;
                       this -> choice_4 = choice_4;
                       this -> choice_5 = choice_5;
                       this -> choice_5 = choice_6;
                   }
/*
void Scenario::Challenge(const Character& character1, const Scenario& scenario1) {
     while (true) {
        int choice;
        std::cout << scenario1.description << std::endl;
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << scenario1.choice_1 << std::endl;

                while (true) {
                    std::cout << scenario1.choice_6 << std::endl;

                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> choice;

                    switch(choice) {
                        case 1:
                            std::cout << scenario1.choice_4 << std::endl;
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
                            std::cout << scenario1.choice_5 << std::endl;
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
                std::cout << scenario1.choice_2 << std::endl;
                //Find an item if you look around.
                //Get randomly dropped item and save it to inventory.
                RandomItem();
                std::cout << "You find a " + RandomItem().type + "!" << std::endl;
                character1.inventory.push_back(RandomItem().type);
                save(character1);
                
                break;
            case 3:
                std::cout << scenario1.choice_3 << std::endl;
                break;
            default:
                std::cout << "Please make a valid choice." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
     }
}*/