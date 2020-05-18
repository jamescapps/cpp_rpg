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


            // Attack choices
            int action;
            std::cout << "What action will you take?: \n(1) Attack\n(2) Defend\n(3) Use Magic\n(4) Heal\n(5) Steal\n(6) Use Item" << std::endl;
            std::cin >> action;

            //Hero actions
            switch(action) {
                case 1: {
                    int char2_damage = abs(ceil(char1_attack - char2_defense));
                    character2.health = character2.health - char2_damage;
                    std::cout << character1.name + " attacks " + character2.name + " and deals " + std::to_string(char2_damage) + " damage."<< std::endl;
                    usleep(2000000);
                    break; 
                }
                case 2: {
                    char1_defense = char1_defense + .5;
                    std::cout << character1.name + " takes a defensive position." << std::endl;
                    usleep(2000000);
                    break;
                }
                case 3: {
                    int char2_damage = abs(ceil(char1_magic - char2_defense));
                    character2.health = character2.health - char2_damage;
                    std::cout << character1.name + " casts a spell on " + character2.name + " and deals " + std::to_string(char2_damage) + " damage." << std::endl;
                    usleep(2000000);
                    break;
                }
                case 4: {
                    character1.health = character1.health + char1_heal;
                    std::cout << character1.name + " heals and receives " + std::to_string(char1_heal) + " health." << std::endl;
                    break;
                }
                case 5: {
                    //Not sure how to handle steal yet.
                    break;
                }
                case 6: {
                    //Not sure how to handle items yet.
                    break;
                }
                default:
                    std::cout << "Please make a valid selection." << std::endl;

            }

            //Should randomize who attacks first and as soon as damage is zero player should die.
            //Monster Attack
            int char1_damage = abs(ceil(char2_attack - char1_defense));
            character1.health = character1.health - char1_damage;
            std::cout << character2.name + " attacks " + character1.name + " and deals " + std::to_string(char1_damage) + " damage." << std::endl;
            usleep(2000000);

            //Make sure health stops at zero.
            character1.health = character1.health < 0 ? 0 : character1.health;
            character2.health = character2.health < 0 ? 0 : character2.health;
            //Check for a victor.
            if (character1.health == 0) {
                std::cout << character1.name + " has died!\n" + character2.name + " WINS the battle!" << std::endl;
                return "End of battle!";
            } else if (character2.health == 0) {
                std::cout << character2.name + " has died.\n" + character1.name + " WINS the battle!" <<std::endl;
                return "End of battle!";
            } else {
                std::cout << "\t" + character1.name + " health: " + std::to_string(character1.health) + "\n\t" + character2.name + " health: " + std::to_string(character2.health) <<std::endl;
                //Reset defense so that extra defense points do not carry over to the next turn.
                char1_defense = character1.Defense();
            }
            return "End of turn!";
        }
};

void CustomChecks(const std::string& name, int& attribute, int& points_left, int&position) {
            //Get and check value for custom character.
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

//Variables to be used in character creation.
std::string char_name;
int char_health = 100;
int char_attack, char_defense, char_magic, char_heal, char_stealth, char_items;

Character CustomCharacter() {
    int points_left = 50;
    int position = 5;

    std::cout << "What is your character's name?: ";
    std::cin.ignore();
    std::getline(std::cin,char_name);
    
    std::cout <<"You have 50 ability points. Use them wisely...Every category must have at least 1 point...\n";
    usleep(1000000);
    //Run function to check and aquire input for each category.
    CustomChecks("attack", char_attack, points_left, position);
    CustomChecks("defense", char_defense, points_left, position);
    CustomChecks("magic", char_magic, points_left, position);
    CustomChecks("heal", char_heal, points_left, position);
    CustomChecks("stealth", char_stealth, points_left, position);
    CustomChecks("items", char_items, points_left, position);

    Character hero(char_name, char_health, char_attack, char_defense, char_magic, char_heal, char_stealth, char_items);
    return hero;
}

Character HeroSelection() {
    int selection;

    std::cout << "What character would you like to be?:\n(1) Warrior\n(2) Tank\n(3) Wizard\n(4) Healer\n(5) Thief\n(6) Custom Character\n";
    std::cin >> selection;

    //Match selection to category and apply attributes.
    switch(selection) {
        case 1: {
            Character hero("Warrior", char_health, 30, 10, 1, 1, 30, 7);
            return hero;
        }
        case 2: {
            Character hero("Tank", char_health, 10, 30, 1, 1, 1, 7);
            return hero;
        }
        case 3: {
            Character hero("Wizard", char_health, 1, 5, 30, 10, 1, 3);
            return hero;
        }
        case 4: {
            Character hero("Healer", char_health, 1, 1, 5, 30, 4, 9);
            return hero;
        }
        case 5: {
            Character hero("Thief", char_health, 5, 3, 1, 1, 30, 10);
            return hero;
        }
        case 6: {
            return CustomCharacter();
        }   
        default:
            std::cout << "Please make a valid selection!\n";
            HeroSelection();
    }
        //Line seems to only be necessary to avoid compiling error.
        Character hero(char_name, char_health, char_attack, char_defense, char_magic, char_heal, char_stealth, char_items);
        return hero; 
}

Character EnemySelection() {
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
     Character monster(char_name, char_health, char_attack, char_defense, char_magic, char_heal, char_stealth, char_items);
     return monster;
}


int main() 
{
    srand(time(NULL));

    Battle::Initiate(HeroSelection(), EnemySelection());

    return 0;
}
