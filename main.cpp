#include <iostream>
#include <string>
#include <limits>
#include <fstream>

#include "./include/character.h"
#include "./include/battle.h"
#include "./include/weapon.h"
#include "./include/character_selection.h"


void continue_game() {
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
            //Will have to adapt this to only output the designated character and not all characters.
             std::cout << output << std::endl;
            if (output.find("Name: ") != std::string::npos) {
                std::string output_name;
                output_name = output.substr(6, (output.length() - 1));
                if (desired_character == output_name) {
                    std::cout << "Welcome back " + desired_character + "! Your journey continues..." << std::endl;
                    continue;
                    //Load the saved data for the character.
                    //Battle::Initiate(SavedCharacter(desired_character), EnemySelection()); 
                } else {
                    std::cout << "Your character is not found.. Perhaps you mispelled the name?" << std::endl;
                    break;
                    // Input buffer does not seem to be clearing.
                    // Can't input correct character 2nd time through.
                }
            }

            //Extract saved attribute values and convert to integers.

            if (output.find("Health: ") != std::string::npos) {
                std::string output_health;
                int saved_health;
                
                output_health = output.substr(9, (output.length() - 1));
                saved_health = std::stoi(output_health);
            }

            if (output.find("Attack: ") != std::string::npos) {
                std::string output_attack;
                int saved_attack;

                output_attack = output.substr(9, (output.length() - 1));
                saved_attack = std::stoi(output_attack);
            }

            if (output.find("Defense: ") != std::string::npos) {
                std::string output_defense;
                int saved_defense;

                output_defense = output.substr(10, (output.length() - 1));
                saved_defense = std::stoi(output_defense);
            }

            if (output.find("Magic: ") != std::string::npos) {
                std::string output_magic;
                int saved_magic;

                output_magic = output.substr(8, (output.length() - 1));
                saved_magic = std::stoi(output_magic);
            }

            if (output.find("Heal: ") != std::string::npos) {
                std::string output_heal;
                int saved_heal;

                output_heal = output.substr(7, (output.length() - 1));
                saved_heal = std::stoi(output_heal);
            }

            if (output.find("Stealth: ") != std::string::npos) {
                std::string output_stealth;
                int saved_stealth;

                output_stealth = output.substr(10, (output.length() - 1));
                saved_stealth = std::stoi(output_stealth);
            }

            if (output.find("Items: ") != std::string::npos) {
                std::string output_items;
                int saved_items;

                output_items = output.substr(8, (output.length() - 1));
                saved_items = std::stoi(output_items);
            }

            Battle::Initiate(SavedCharacter(desired_character, saved_health, saved_attack, saved_defense, saved_magic, saved_heal, saved_stealth, saved_items), EnemySelection()); 
        }
        save_file.close();
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