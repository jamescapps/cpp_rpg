#ifndef BATTLE_H
#define BATTLE_H

#include <string>
#include "character.h"


class Battle {
    public:
        static void Initiate(const Character& character1, const Character& character2);
        static std::string AttackResult(const Character& character1, const Character& character2);
};

#endif