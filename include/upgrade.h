#ifndef UPGRADE_H
#define UPGRADE_H

#include <string>


void upgrade(const std::string& name, int& attribute, int& points_left);
void check_for_upgrade(const Character& character1);

#endif