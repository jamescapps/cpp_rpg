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


void AdventureGame(const Character& character1) {
    std::cout << "Welcome " + character1.name + "! Your adventure awaits..." << std::endl;
     usleep(2000000);
    
     while (true) {
        int choice;
        std::cout << "You come to the entrance to a cave. What would you like to do?\n(1) Go inside\n(2) Look around\n(3) Run away" << std::endl;
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << "You have chosen to go inside." << std::endl;

                while (true) {
                    std::cout << "You are only a few feet in when a monster comes out of nowhere.\nWhat will you do?\n(1) Fight\n(2)Run away" << std::endl;

                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> choice;

                    switch(choice) {
                        case 1:
                            std::cout << "You choose to fight!" << std::endl;
                            Battle::Initiate(character1, EnemySelection());

                            //Will need to seperate random item into it's own function because it will be used after every battle.
                            while(true) {
                                char item_choice;
                                std::cout << "\n\nThe enemy has dropped an item. Would you like to see what it is? (y) (n)" << std::endl;
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                std::cin >> item_choice;

                                if (std::tolower(item_choice) == 'y') {
                                    //Get randomly dropped item and save it to inventory.
                                    Item Dropped_Item = RandomItem();
                                    std::cout << "You find a " + Dropped_Item.type + "!" << std::endl;
                                    character1.inventory.push_back(Dropped_Item.type);
                                    save(character1);
                                    //Continue on with game.
                                } else if (std::tolower(item_choice) == 'n') {
                                    std::cout << "You go about your way." << std::endl;
                                    //Continue on with game.
                                } else {
                                    std::cout << "Please make a valid choice." << std::endl;
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                                }
                            }
                            
                           break;
                        case 2:
                            std::cout << "You choose to run!\n" << std::endl;
                            //Have a random function that will randomly choose if running away is successful.
                            break;
                        default:
                            std::cout << "Please make a valid choice." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    }
                }
            case 2:
                std::cout << "You have chosen to look around." << std::endl;
                //Find an item if you look around.
                break;
            case 3:
                std::cout << "You have chosen to run away." << std::endl;
                break;
            default:
                std::cout << "Please make a valid choice." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
     }
}