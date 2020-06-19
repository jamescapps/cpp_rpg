#ifndef SCENARIO_H
#define SCENARIO_H

#include <unistd.h>
#include <string>


/* Structure for creating a reusable adventure scenario.
        Overall description of scenario.
        Pre battle choice.
        Description of the battle.
        Choice to fight or run away.
        Choice to pick up the randomly dropped item.
*/
class Scenario {
    public:
        std::string description;
        std::string choice_1;
        std::string choice_2;
        std::string pre_battle;
        std::string choice_3;
        std::string choice_4;
        std::string choice_5;
        std::string choice_6;

        Scenario(std::string description, 
                 std::string choice_1, 
                 std::string choice_2, 
                 std::string choice_3, 
                 std::string choice_4, 
                 std::string choice_5, 
                 std::string choice_6
                 );
};

#endif 
