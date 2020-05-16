#include <vector> 
#include <ctime> 
#include <numeric> 
#include <math.h> 
#include <cstdio> 
#include <iostream> 
#include <unistd.h>


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

            int char1_items = character1.Items();
            int char2_items = character2.Items();
               
            //Add more here later...
            
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

Character HeroSelection() {
    //Hero
    std::string hero_name;
    int hero_health = 100;
    int hero_attack, hero_defense, hero_magic, hero_heal, hero_stealth, hero_items, points_left; 
    int selection;

    std::cout << "What character would you like to be?:\n(1) Warrior\n(2) Tank\n(3) Wizard\n(4) Healer\n(5) Thief\n(6) Custom Character\n";
    std::cin >> selection;

    //Match selection to category and apply attributes.
    switch(selection) {
        case 1:
            std::cout << "You are a warrior!\n";
            hero_name = "Warrior";
            hero_attack = 30;
            hero_defense = 10;
            hero_magic = 1;
            hero_heal = 1;
            hero_stealth = 1;
            hero_items = 7;
            break;
        case 2:
            std::cout << "You are a tank!\n";
            hero_name = "Tank";
            hero_attack = 10;
            hero_defense = 30;
            hero_magic = 1;
            hero_heal = 1;
            hero_stealth = 1;
            hero_items = 7;
            break;
        case 3: 
            std::cout << "You are a wizard!\n";
            hero_name = "Wizard";
            hero_attack = 1;
            hero_defense = 5;
            hero_magic = 30;
            hero_heal = 10;
            hero_stealth = 1;
            hero_items = 3;
            break;
        case 4:
            std::cout << "You are a healer!\n";
            hero_name = "Healer";
            hero_attack = 1;
            hero_defense = 1;
            hero_magic = 5;
            hero_heal = 30;
            hero_stealth = 4;
            hero_items = 9;
            break;
        case 5:
            std::cout << "You are a thief!\n";
            hero_name = "Thief";
            hero_attack = 5;
            hero_defense = 3;
            hero_magic = 1;
            hero_heal = 1;
            hero_stealth = 30;
            hero_items = 10;
            break;
        case 6:
            //Custom character
            points_left = 50;
            std::cout << "What is your character's name?: "; 
            std::cin >> hero_name;
            std::cout <<"You have 50 ability points. Use them wisely...Every category must have at least 1 point...\n";
            usleep(2000000);
            
            // Get and check attack value.
            std::cout << "How many points would you like to give to the attack category?: ";
            std::cin >> hero_attack;
            if (hero_attack > 45 || hero_attack == 0 ) {
                std::cout << "Please enter a value between 1 and 45.." << std::endl;
                // Repeat process of getting attack points..
            } else {
                points_left = points_left - hero_attack;
                std::cout << "You have " + std::to_string(points_left) + " points left." << std::endl;
            }
            
            //Get and check defense value.
            std::cout << "How many points would you like to give to the defense category?: ";
            std::cin >> hero_defense;
            if (hero_defense == 0 || (hero_defense + points_left) > 46 ) {
                std::cout << "Value must be between 1 and 45..." << std::endl;
                // Repeat process of getting defense points...
            } else {
                points_left = points_left - hero_defense;
                std::cout << "You have " + std::to_string(points_left) + " points left." << std::endl;
            }

            //Get and check magic value.
            std::cout << "How many points would you like to give to the magic category?:  ";
            std::cin >> hero_magic;
            if (hero_magic == 0 || (hero_magic + points_left) > 46) {
                std::cout << "Value must be between 1 and 45..." << std::endl;
                // Repeat process of getting magic points...
            } else {
                points_left = points_left - hero_magic;
                std::cout << "You have " +  std::to_string(points_left) + " points left." << std::endl;
            }
            
            //Get and check heal points.
            std::cout << "How many points would you like to give to the heal category?: ";
            std::cin >> hero_heal;
            if (hero_heal == 0 || (hero_heal + points_left) > 46) {
                std::cout << "Value must be between 1 and 45..." << std::endl;
                // Repeat process of getting heal  points...
            } else {
                points_left = points_left - hero_heal;
                std::cout << "You have " + std::to_string(points_left) + " points left." << std::endl;
            }

            //Get and check stealth points.
            std::cout << "How many points would you like to give to the stealth category?: ";
            std::cin >> hero_stealth;
            if (hero_stealth == 0 || (hero_stealth + points_left) > 46) {
                std::cout << "Value must be between 1 and 45..." << std::endl;
                // Repeat process of getting stealth points...
            } else {
                points_left = points_left - hero_stealth;
                std::cout << "You have " + std::to_string(points_left) + " points left." << std::endl;
            }

            //Get and check items points.
            std::cout << "How many points would you like to give to the items category?: ";
            std::cin >> hero_items;
            
            if (hero_items == 0 || (hero_items + points_left) > 46) {
                std::cout << "Value must be between 1 and 45..." << std::endl;
                // Repeat process of getting items points...
            } else {
                points_left = points_left - hero_items;
                std::cout << "You have " + std::to_string(points_left) + " points left." << std::endl;
                // Give total of points and if any extra let them add to
                // categories.
            }

            break; 
        default:
            std::cout << "Please make a valid selection!\n";
            HeroSelection();
    }

        Character hero(hero_name, hero_health, hero_attack, hero_defense, hero_magic, hero_heal, hero_stealth, hero_items);
        return hero; 
}            

Character EnemySelection() {
    //Enemy
    std::string monster_name;
    int monster_health, monster_attack, monster_defense, monster_magic, monster_heal, monster_stealth, monster_items;
  
    //Get random enemy
    //I don't think the randomizer is working correctly...seems like it's always
    //the demon...
    std::vector<std::string> enemies = {"Demon", "Orc", "Giant Spider", "Troll", "Dragon"};
    std::string enemy = enemies[rand() % enemies.size()];

    //Check which enemy and apply attributes.
    if (enemy.compare("Demon")) {
         std::cout << "You encounter a demon!\n";
         monster_name = "Demon";
         monster_health = 200;
         monster_attack = 15;
         monster_defense = 5;
         monster_magic = 10;
         monster_heal = 1;
         monster_stealth = 1;
         monster_items = 1;
     } else if (enemy.compare("Orc")) {
         std::cout << "You encounter an Orc!\n";
         monster_name = "Orc";
         monster_health = 50;
         monster_attack = 5;
         monster_defense = 2;
         monster_magic = 2;
         monster_heal = 1;
         monster_stealth = 1;
         monster_items = 1;
     } else if (enemy.compare("Giant Spider")) {
         std::cout << "You encounter a Giant Spider!\n";
         monster_name = "Giant Spider";
         monster_heal = 100;
         monster_attack = 10;
         monster_defense = 5;
         monster_magic = 1;
         monster_heal = 1;
         monster_stealth = 1;
         monster_items = 1;
     } else if (enemy.compare("Troll")) {
         std::cout << "You encounter a Troll!\n";
         monster_name = "Troll";
         monster_health = 20;
         monster_attack = 3;
         monster_defense = 3;
         monster_magic = 1;
         monster_heal = 1;
         monster_stealth = 1;
         monster_items = 1;
     } else if (enemy.compare("Dragon")) {
         std::cout << "You encounter a Dragon!\n";
         monster_name = "Dragon";
         monster_health = 250;
         monster_attack = 20;
         monster_defense = 7;
         monster_magic = 5;
         monster_heal = 1;
         monster_stealth = 1;
         monster_items = 1;
     } else {
         std::cout << "Something went wrong..." << std::endl;
     }

     Character monster(monster_name, monster_health, monster_attack, monster_defense, monster_magic, monster_heal, monster_stealth, monster_items);
     return monster;
}


int main() 
{
    srand(time(NULL));

    Battle::Initiate(HeroSelection(), EnemySelection());


    return 0;
}
