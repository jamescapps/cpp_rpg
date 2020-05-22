#ifndef CHARACTER_SELECTION_H
#define CHARACTER_SELETION_H

#include <string>
#include "character.h"


void CustomChecks(const std::string& name, int& attribute, int& points_left, int& position);

static std::string char_name;
static int char_health = 100;
static int char_attack, char_defense, char_magic, char_heal, char_stealth, char_items;

Character SavedCharacter();
Character CustomCharacter();
Character HeroSelection();
Character EnemySelection();

#endif