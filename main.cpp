#include <string>

#include "./include/character.h"
#include "./include/battle.h"
#include "./include/weapon.h"
#include "./include/character_selection.h"


int main() 
{
    srand(time(NULL));
    Battle::Initiate(HeroSelection(), EnemySelection());

    return 0;
}