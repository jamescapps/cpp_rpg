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


int main() 
{
    srand(time(NULL));
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
    

    return 0;
}