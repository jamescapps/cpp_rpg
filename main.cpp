#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>

#include "./include/character.h"
#include "./include/battle.h"
#include "./include/weapon.h"
#include "./include/character_selection.h"
#include "./include/continue.h"
#include "./include/adventure.h"


void AdventureMenu() {
    bool in_menu = true;
    while(in_menu = true) {
        int selection;
        
        std::cout << "  **Adventure** "      << std::endl;
        std::cout << " (1) New Game"      << std::endl;
        std::cout << " (2) Continue"      << std::endl;
        std::cout << " (3) Main Menu "      << std::endl; 
        std::cin >> selection;

        switch(selection) {
            case 1: 
                AdventureGame(HeroSelection());
                break; 
            case 2: {
                AdventureGame(ContinueGame());
                break;
            }
            case 3: 
                in_menu = false;
                break;
            default: 
                std::cout << "Please make a valid selection." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        break;
    }
}

void BattleMenu() {
    bool in_menu = true;
    while(in_menu = true) {
        int selection;
        
        std::cout << "  **Battle** "      << std::endl;
        std::cout << " (1) New Game"      << std::endl;
        std::cout << " (2) Continue"      << std::endl;
        std::cout << " (3) Main Menu "      << std::endl; 
        std::cin >> selection;

        switch(selection) {
            case 1: 
                Battle::Initiate(HeroSelection(), EnemySelection()); 
                break; 
            case 2: {
                Battle::Initiate(ContinueGame(), EnemySelection()); 
                break;
            }
            case 3: 
                in_menu = false;
                break;
            default: 
                std::cout << "Please make a valid selection." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        break;
    }
}


int main() 
{
    srand(time(NULL));
    while (true) {
        int selection;
        
        std::cout << "  **Main Menu** "      << std::endl;
        std::cout << " (1) Adventure  "      << std::endl;
        std::cout << " (2) Battle     "      << std::endl;
        std::cout << " (3) Options    "      << std::endl; 
        std::cin >> selection;

        switch(selection) {
            case 1: 
                AdventureMenu();
                break; 
            case 2: {
                BattleMenu();
                break;
            }
            case 3: 
                //Go to options menu to select difficulty.
                break;
            default: 
                std::cout << "Please make a valid selection." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    

    return 0;
} 