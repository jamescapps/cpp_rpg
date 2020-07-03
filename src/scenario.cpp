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


Scenario::Scenario(std::string description, std::string choice_1, std::string choice_2, 
                   std::string choice_3, std::string pre_battle, std::string choice_4, 
                   std::string choice_5) {

                       this -> description = description;
                       this -> choice_1 = choice_1;
                       this -> choice_2 = choice_2;
                       this -> choice_3 = choice_3;
                       this -> pre_battle = pre_battle;
                       this -> choice_4 = choice_4;
                       this -> choice_5 = choice_5;
                   }


/*
    This section has a group of random initial descriptions for the an adventure scenario, followed by a corresponding pre battle
    description, after standard yes/no questions. Those values are found randomly when the template for the adventure is inacted.
    Thus allowing the user to play through never ending adventure scenarios.
*/

Scenario RandomScenario() {
    std::vector<std::string> descriptions = {"You come to the entrance to a cave. What would you like to do?\n(1) Go inside\n(2) Look around\n(3) Run away", 
                                            "A monster approaches you and asks you for a favor. What would you like to do?\n(1) Hear him out\n(2) Tell him to stop where he is\n(3) Run away",
                                            "You see a monster heading towards an innocent looking person. What would you like to do?\n(1) Investigate\n(2) Wait\n(3) Run away",
                                            "A monster calls you a name. What would you like too do?\n(1) Insult\n(2) Let it go\n(3) Run away",
                                            "You come to a clearing in the woods. What would you like to do?\n(1) Go inside\n(2) Look around\n(3) Run away",
                                            "Something smells strange. What would you like to do?\n(1) Follow your nose\n(2) Look around\n(3) Run away", 
                                            };


    std::vector<std::string> pre_battles = {"You are only a few feet in when a monster comes out of nowhere.\nWhat will you do?\n(1) Fight\n(2)Run away", 
                                            "He decides you look delicious.\nWhat will you do?\n(1) Fight\n(2)Run away",
                                            "The monster spots you!\nWhat will you do?\n(1) Fight\n(2)Run away",
                                            "The monster heads towards you!\nWhat will you do?\n(1) Fight\n(2)Run away",
                                            "You are only a few feet in when a monster comes out of nowhere.\nWhat will you do?\n(1) Fight\n(2)Run away",
                                            "You discover a monster!\nWhat will you do?\n(1) Fight\n(2)Run away" 
                                            };

    //Randomize description, then use same index to get relevant pre_battle.
    int rand_desc = std::rand() % descriptions.size();

    // Standard Choices
    std::string choice_1 = "You choose 1";
    std::string choice_2 = "You choose 2";
    std::string choice_3 = "You choose 3";
    std::string choice_4 = "You choose to fight!";
    std::string choice_5 = "You choose to run away";

    Scenario Challenge(descriptions[rand_desc], choice_1, choice_2, choice_3, pre_battles[rand_desc], choice_4, choice_5);
    return Challenge;
}
