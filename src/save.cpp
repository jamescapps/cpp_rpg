#include <iostream> 
#include <fstream>
#include <iterator> 

#include "../include/character.h"
#include "../include/character_selection.h"
#include "../include/battle.h"
#include "../include/weapon.h"
#include "../include/upgrade.h"
#include "../include/save.h"


void save(const Character& character1) {
    std::ofstream save_file;
    save_file.open("save_data/" + character1.name + ".txt", std::ios::trunc);

    save_file << "\nName: "      << character1.name      << std::endl;
    save_file << "\tLevel: "     << character1.level     << std::endl;
    save_file << "\tWins: "      << character1.wins      << std::endl;
    save_file << "\tLosses: "    << character1.losses    << std::endl;
    save_file << "\tHealth: "    << character1.health    << std::endl;
    save_file << "\tAttack: "    << character1.attack    << std::endl;
    save_file << "\tDefense: "   << character1.defense   << std::endl;
    save_file << "\tMagic: "     << character1.magic     << std::endl;
    save_file << "\tHeal: "      << character1.heal      << std::endl;
    save_file << "\tItems: "     << character1.items     << std::endl;
    save_file << "\tExp: "       << character1.exp       << std::endl;

    //Save inventory vector
    save_file << "\tInventory: "; 
    std::ostream_iterator<std::string> output_iterator(save_file, ", ");
    std::copy(character1.inventory.begin(), character1.inventory.end(), output_iterator);

    save_file.close();

    std::cout << "Your progress has been saved!" << std::endl;
}