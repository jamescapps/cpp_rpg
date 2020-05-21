#include <iostream>
#include <string>
#include <limits>
#include <fstream>

#include "./include/character.h"
#include "./include/battle.h"
#include "./include/weapon.h"
#include "./include/character_selection.h"


int continue_game() {
    while (true) {
        std::ifstream save_file;
        save_file.open("rpg_save_data.txt");

        std::string output;
        std::string desired_character;

        std::cout << "What is the name of the character you wish to continue your adventure with?: ";
        std::cin.clear();
        std::cin.ignore();
        std::getline(std::cin >> std::ws, desired_character);
        
        while (getline(save_file, output)) {
            
            if (output.find("Name: ") != std::string::npos) {
                if (desired_character == output.substr(6, (output.length() - 1))) {
                    std::cout << "Welcome back " + desired_character + "! Your journey continues..." << std::endl;
                    std::cout << output << std::endl;
                    //Only printing out name.
                    //Load the saved data for the character.
                } else {
                    std::cout << "Your character is not found.. Perhaps you mispelled the name?" << std::endl;
                    break;
                    // Input bugger does not seem to be clearing.
                    // Can't input correct character 2nd time through.
                }
            }
        }
        save_file.close();
    }
    
}

//Opening menu
int main_menu() {
    while(true) {
        int selection;
        
        std::cout << " **MAIN MENU**"    << std::endl;
        std::cout << " (1) New Game"     << std::endl;
        std::cout << " (2) Continue"     << std::endl;
        std::cout << " (3) Options"      << std::endl; 
        std::cin >> selection;

        switch(selection) {
            case 1: 
                Battle::Initiate(HeroSelection(), EnemySelection()); 
                break; 
            case 2: {
                //Run function to continue game
                continue_game();
                

                break;
            }
            case 3: 
                //Run function to enter a difficuly setting menu.
                break;
            default: 
                std::cout << "Please make a valid selection." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } 
} 


int main() 
{
    srand(time(NULL));
    main_menu();
    

    return 0;
}