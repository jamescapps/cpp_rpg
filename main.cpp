#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>

#include "./include/character.h"
#include "./include/battle.h"
#include "./include/weapon.h"
#include "./include/character_selection.h"

//Current issues
//  Not returning to top of loop if continue character not found.
//  Need to seperate continue into it's own file.

void continue_game() {
    while (true) {
        std::ifstream save_file("rpg_save_data.txt");
        std::string output, desired_character, output_name;
        int saved_level, saved_wins, saved_losses, saved_health, saved_attack, saved_defense, saved_magic, saved_heal, saved_stealth, saved_items, saved_exp;

        std::cout << "What is the name of the character you wish to continue your adventure with?: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin >> std::ws, desired_character);
    
        while (std::getline(save_file, output)) {
            //Will have to adapt this to only output the designated character and not all characters.
            if (output.find("Name: ") != std::string::npos) {
                output_name = output.substr(6, (output.length() - 1));
                if (desired_character == output_name) {
                    std::cout << "Welcome back " + output_name + "! Your journey continues..." << std::endl;
                    continue;
                    //Load the saved data for the character.
                    //Battle::Initiate(SavedCharacter(desired_character), EnemySelection()); 
                } else {
                    std::cout << "Your character is not found.. Perhaps you mispelled the name?" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
                    // Input buffer does not seem to be clearing.
                    // Can't input correct character 2nd time through.
                }
            }

            //Extract saved attribute values and convert to integers.

            if (output.find("Level: ") != std::string::npos) {
                std::string output_level;
                std::cout << output << std::endl;
                output_level = output.substr(8, (output.length() - 1));
                saved_level = std::stoi(output_level);
            }

            if (output.find("Wins: ") != std::string::npos) {
                std::string output_wins;
                std::cout << output << std::endl;
                output_wins = output.substr(7, (output.length() - 1));
                saved_wins = std::stoi(output_wins);
            }

            if (output.find("Losses: ") != std::string::npos) {
                std::string output_losses;
                std::cout << output << std::endl;
                output_losses = output.substr(9, (output.length() - 1));
                saved_losses = std::stoi(output_losses);
            }

            if (output.find("Health: ") != std::string::npos) {
                std::string output_health;
                std::cout << output << std::endl;
                output_health = output.substr(9, (output.length() - 1));
                saved_health = std::stoi(output_health);
            }

            if (output.find("Attack: ") != std::string::npos) {
                std::string output_attack;
                std::cout << output << std::endl;
                output_attack = output.substr(9, (output.length() - 1));
                saved_attack = std::stoi(output_attack);
            }

            if (output.find("Defense: ") != std::string::npos) {
                std::string output_defense;
                std::cout << output << std::endl;
                output_defense = output.substr(10, (output.length() - 1));
                saved_defense = std::stoi(output_defense);
            }

            if (output.find("Magic: ") != std::string::npos) {
                std::string output_magic;
                std::cout << output << std::endl;
                output_magic = output.substr(8, (output.length() - 1));
                saved_magic = std::stoi(output_magic);
            }

            if (output.find("Heal: ") != std::string::npos) {
                std::string output_heal;
                std::cout << output << std::endl;
                output_heal = output.substr(7, (output.length() - 1));
                saved_heal = std::stoi(output_heal);
            }

            if (output.find("Stealth: ") != std::string::npos) {
                std::string output_stealth;
                std::cout << output << std::endl;
                output_stealth = output.substr(10, (output.length() - 1));
                saved_stealth = std::stoi(output_stealth);
            }

            if (output.find("Items: ") != std::string::npos) {
                std::string output_items;
                std::cout << output << std::endl;
                output_items = output.substr(8, (output.length() - 1));
                saved_items = std::stoi(output_items);
            }

            if (output.find("Exp: ") != std::string::npos) {
                std::string output_exp;
                std::cout << output << std::endl;
                output_exp = output.substr(6, (output.length() - 1));
                saved_exp = std::stoi(output_exp);
            }
        }

        save_file.close();

        char response;
        std::cout << "Are you ready to continue?: (y) (n)" << std::endl;
        std::cin >> response;

        if (std::tolower(response) == 121) {
            Battle::Initiate(SavedCharacter(output_name, saved_level, saved_wins, saved_losses, saved_health, saved_attack, saved_defense, saved_magic, saved_heal, saved_stealth, saved_items, saved_exp), EnemySelection()); 
        } else if (std::tolower(response) == 110) {
            std::cout << "Well what are you waiting for?" <<std::endl;
        } else {
            std::cout << std::tolower(response);
        }
        
    }    
}

//Opening menu
void main_menu() {
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