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

//Reusable function for adventure scenarios.
//Eventually could create random scenarios.
//Probably should make Template a Class.

void AdventureGame(const Character& character1) {
    std::cout << "Welcome " + character1.name + "! Your adventure awaits..." << std::endl;
     usleep(2000000);
    
    std::string thisisatest = "You come to the entrance to a cave. What would you like to do?\n(1) Go inside\n(2) Look around\n(3) Run away";
    std::string test2 = "You come to the entrance to a cave. What would you like to do?\n(1) Go inside\n(2) Look around\n(3) Run away";
    std::string test3 = "You choose to go inside.";
    std::string test4 = "You choose to look around.";
    std::string test5 = "You choose to run away";
    std::string test6 = "You choose to fight!";
    std::string test7 = "You choose to run away";
    std::string test8 = "You are only a few feet in when a monster comes out of nowhere.\nWhat will you do?\n(1) Fight\n(2)Run away";

    Scenario challenge_1(thisisatest, test2, test3, test4, test5, test6, test7, test8);
  
}