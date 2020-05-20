#include <iostream>
#include <string>
#include <limits>

#include "./include/character.h"
#include "./include/battle.h"
#include "./include/weapon.h"
#include "./include/character_selection.h"


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
                //Run function to start a new game.
                Battle::Initiate(HeroSelection(), EnemySelection());  
            case 2: 
                //Run function to continue game
            case 3: 
                //Run function to enter a difficuly setting menu.
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