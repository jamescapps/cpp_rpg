#ifndef CHARACTER_SELECTION_H
#define CHARACTER_SELETION_H

#include <string>
#include "character.h"


static std::string char_name;
static int char_health = 100;
static int char_attack, char_defense, char_magic, char_heal, char_stealth, char_items;

Character SavedCharacter(const std::string& saved_name, int& saved_health, int& saved_attack, int& saved_defense, int& saved_magic, int& saved_heal, int& saved_stealth, int& saved_items);
void CustomChecks(const std::string& name, int& attribute, int& points_left, int& position);
Character CustomCharacter();
Character HeroSelection();
Character EnemySelection();

#endif