#include <iostream> 
#include <unistd.h>
#include <string>
#include <vector> 
#include <numeric> 
#include <math.h> 
#include <cstdio>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>


// Current issues
//      Should probably start seperating into multiple files.

class Character {
    private: 
        mutable int attack, defense, magic, heal, stealth, items;
       
    public:
        mutable std::string name;
        mutable int health;
        
        //Character will have 50 available points, every category must have at
        //least 1 point.
        Character(std::string name, int health,  int attack, int defense, 
                        int magic, int heal, int stealth, int items) {
            this -> name = name;
            this -> health = health;
            this -> attack = attack;
            this -> defense = defense;
            this -> magic = magic; 
            this -> heal = heal;
            this -> stealth = stealth;
            this -> items = items;
        }

        int Attack() const {
            return std::rand() % this -> attack;
        }

        int Defense() const {
            return std::rand() % this -> defense;
        }

        int Magic() const {
            return std::rand() % this -> magic;
        }

        int Heal() const {
            return std::rand() % this -> heal;
        }

        int Stealth() const {
            return std::rand() % this -> stealth;
        }

        int Items() const {
            return std::rand() % this -> items;
        }
        // Add more functions here for other actions. 
};

class Weapon {
    //Not using yet... but eventually will play into attack formula.
    private:
        int damage_amt;
        int stability;

    public:
        std::string type;
    
    Weapon(std::string type, int damage_amt, int stability) {
        this -> type = type;
        this -> damage_amt = damage_amt;
        this -> stability = stability;
    }
};

class Battle {
    public:
        static void Initiate(const Character& character1, const Character& character2) {
            std::cout << character1.name + " encounters " + character2.name + "!"<< std::endl;
            while (true) {
                if (Battle::AttackResult(character1, character2).compare("End of battle!") == 0) {
                    std::cout << "End of battle! \n";
                    break;
                }
            }
        }
        
        //Battle logic
        static std::string AttackResult(const Character& character1, const Character& character2) {
            int char1_attack = character1.Attack();
            int char2_attack = character2.Attack();
   
            int char1_defense = character1.Defense();
            int char2_defense = character1.Defense();
            
            int char1_magic = character1.Magic();
            int char2_magic = character2.Magic();

            int char1_heal = character1.Heal();
            int char2_heal = character2.Heal();

            int char1_stealth = character1.Stealth();
            int char2_stealth = character2.Stealth();

            int char1_items = character1.Items();
            int char2_items = character2.Items();
               
            //Add more here later...
            //Should randomize who attacks first and as soon as damage is zero player should die.
            //Health and Damage
            int char1_damage = abs(ceil(char2_attack - char1_defense));
            character1.health = character1.health - char1_damage;

            int char2_damage = abs(ceil(char1_attack - char2_defense));
            character2.health = character2.health - char2_damage; 

            printf("%s attacks %s and deals %d damage.\n",
                    character1.name.c_str(),
                    character2.name.c_str(),
                    char2_damage); 
            usleep(2000000);
             
            printf("%s attacks %s and deals %d damage.\n",
                    character2.name.c_str(),
                    character1.name.c_str(),
                    char1_damage);
            usleep(2000000);
            
            //Check for a victor...
            if (character1.health < 0) {
                character1.health = 0;
            }

            if (character2.health < 0) {
                character2.health = 0;
            }
 
            if (character1.health == 0) {
                printf("%s has died!\n%s WINS the battle!\n",
                        character1.name.c_str(),
                        character2.name.c_str());
                return "End of battle!";
            } else if (character2.health == 0) {
                printf("%s has died\n%s WINS the battle!!\n",
                        character2.name.c_str(),
                        character1.name.c_str());
                return "End of battle!";
            } else { 
                printf("\t%s health: %d\n\t%s health: %d\n",
                        character1.name.c_str(),
                        character1.health,
                        character2.name.c_str(),
                        character2.health);
            }
            return "End of turn!";
        }
};

void CustomChecks(const std::string& name, int& attribute, int& points_left, int&position) {
            //Get and check value.
            while (true) {
                std::vector<int> v;
                std::cout << "How many points would you like to give to the " + name + " category?";
                std::cin >> attribute;

                //Make sure an integer is input.
                while(!std::cin) {
                    std::cout << "Please enter an integer: ";
                    std::cin.clear();
                    std::cin.ignore();
                    std::cin >> attribute;
                }

                //Make sure number is within parameters.
                if (attribute == 0 || attribute > (points_left - position)) {
                    std::cout << "Value must be between 1 and " + std::to_string(points_left - position) << std::endl;
                    // Repeat process of getting defense points...
                } else {
                    points_left = points_left - attribute;
                    if (points_left != 0) {
                        std::cout << "You have " + std::to_string(points_left) + " points left." << std::endl;
                    }
                    position--;
                    break;
                }
        }
 }

Character HeroSelection() {
    //Hero
    std::string hero_name;
    int hero_health = 100;
    int hero_attack, hero_defense, hero_magic, hero_heal, hero_stealth, hero_items;
    int selection;

    std::cout << "What character would you like to be?:\n(1) Warrior\n(2) Tank\n(3) Wizard\n(4) Healer\n(5) Thief\n(6) Custom Character\n";
    std::cin >> selection;

    //Match selection to category and apply attributes.
    switch(selection) {
        case 1: {
            Character hero("Warrior", hero_health, 30, 10, 1, 1, 30, 7);
            return hero;
        }
        case 2: {
            Character hero("Tank", hero_health, 10, 30, 1, 1, 1, 7);
            return hero;
        }
        case 3: {
            Character hero("Wizard", hero_health, 1, 5, 30, 10, 1, 3);
            return hero;
        }
        case 4: {
            Character hero("Healer", hero_health, 1, 1, 5, 30, 4, 9);
            return hero;
        }
        case 5: {
            Character hero("Thief", hero_health, 5, 3, 1, 1, 30, 10);
            return hero;
        }
        case 6: {
            //Custom character
            int points_left = 50;
            int position = 5;

            std::cout << "What is your character's name?: ";
            std::cin.ignore();
            std::getline(std::cin,hero_name);
            
            std::cout <<"You have 50 ability points. Use them wisely...Every category must have at least 1 point...\n";
            usleep(1000000);
            //Run function to check and aquire input for each category.
            CustomChecks("attack", hero_attack, points_left, position);
            CustomChecks("defense", hero_defense, points_left, position);
            CustomChecks("magic", hero_magic, points_left, position);
            CustomChecks("heal", hero_heal, points_left, position);
            CustomChecks("stealth", hero_stealth, points_left, position);
            CustomChecks("items", hero_items, points_left, position);

            Character hero(hero_name, hero_health, hero_attack, hero_defense, hero_magic, hero_heal, hero_stealth, hero_items);
            return hero;
        }   
        default:
            std::cout << "Please make a valid selection!\n";
            HeroSelection();
    }
        //Line seems to only be necessary to avoid compiling erro.
        Character hero(hero_name, hero_health, hero_attack, hero_defense, hero_magic, hero_heal, hero_stealth, hero_items);
        return hero; 
}

Character EnemySelection() {
    //Enemy
    std::string monster_name;
    int monster_health, monster_attack, monster_defense, monster_magic, monster_heal, monster_stealth, monster_items;
    //Get a random enemy
    std::string enemies[5] = {"Demon", "Orc", "Giant Spider", "Troll", "Dragon"};
    std::string enemy;
    int rand_index = rand() % 5;
    enemy = enemies[rand_index];
          
    //Check which enemy and apply attributes.
    if (enemy == "Demon") {
        Character monster("Demon", 200, 15, 5, 10, 1, 1, 1);
        return monster;
     } else if (enemy == "Orc") {
        Character monster("Orc", 50, 5, 2, 2, 1, 1, 1);
        return monster;
     } else if (enemy == "Giant Spider") {
        Character monster("Giant Spider", 100, 10, 5, 1, 1, 1, 1);
        return monster;
     } else if (enemy == "Troll") {
        Character monster("Troll", 20, 3, 3, 1, 1, 1, 1);
        return monster;
     } else if (enemy == "Dragon") {
        Character monster("Dragon", 250, 20, 7, 5, 1, 1, 1);
        return monster;
     } else {
         std::cout << "Something went wrong..." << std::endl;
     }
     //Line seems to only be necessary to avoid compiling warning.
     Character monster(monster_name, monster_health, monster_attack, monster_defense, monster_magic, monster_heal, monster_stealth, monster_items);
     return monster;
}


int main() 
{
    srand(time(NULL));

    Battle::Initiate(HeroSelection(), EnemySelection());

    return 0;
}
