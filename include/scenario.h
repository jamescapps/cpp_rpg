#ifndef SCENARIO_H
#define SCENARIO_H

#include <unistd.h>
#include <string>

#include "character.h"


/* Structure for creating a reusable adventure scenario.
        Overall description of scenario.
        Pre battle choice.
        Description of the battle.
        Choice to fight or run away.
        Choice to pick up the randomly dropped item.
*/
class Scenario {
    public:
        mutable std::string description;
        mutable std::string choice_1;
        mutable std::string choice_2;
        mutable std::string choice_3;
        mutable std::string pre_battle;
        mutable std::string choice_4;
        mutable std::string choice_5;

        Scenario(std::string description, std::string choice_1, std::string choice_2, 
                 std::string choice_3, std::string pre_battle,  std::string choice_4, 
                 std::string choice_5);

        //void Challenge(const Character& character1, const Scenario& scenario1);
};

#endif 
