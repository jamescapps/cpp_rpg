#include <vector> 
#include <ctime> 
#include <numeric> 
#include <math.h> 
#include <cstdio> 
#include <iostream> 
#include <unistd.h>


class Character {
    private: 
        mutable int attack, defense, magic, heal, stealth;
       
    public:
        mutable  std::string name;
        mutable int health;
  
        Character(std::string name, int health,  int attack, int defense, 
                        int magic, int heal, int stealth) {
            this -> name = name;
            this -> health = health;
            this -> attack = attack;
            this -> defense = defense;
            this -> magic = magic; 
            this -> heal = heal;
            this -> stealth = stealth;
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

        // Add more functions here for other actions. 
};

class Weapon {
    //Not using yet...
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

        static std::string AttackResult(const Character& character1, const Character& character2) {
            int char1_attack = character1.Attack();
            int char2_attack = character2.Attack();
   
            int char1_defense = character1.Defense();
            int char2_defense = character1.Defense();
            
            int char1_magic = character1.Magic();
            int char2_magic = character2.Magic();

            int char1_heal = character1.Heal();
            int char2_heal = character2.Heal();
               
            //Add more here later...
            
            //Health and Damage
            int char1_damage = abs(ceil(char2_attack - char1_defense));
            character1.health = character1.health - char1_damage;

            int char2_damage = abs(ceil(char1_attack - char2_defense));
            character2.health = character2.health -char2_damage; 

            printf("%s attacks %s and deals %d damage\n",
                    character1.name.c_str(),
                    character2.name.c_str(),
                    char2_damage); 

            usleep(2000000);
             
            printf("%s attacks %s and deals %d damage\n",
                    character2.name.c_str(),
                    character1.name.c_str(),
                    char1_damage);

            usleep(2000000);

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

Character  HeroSelection() {
    //Hero
    std::string hero_name;
    int hero_health, hero_attack, hero_defense, hero_magic, hero_heal, hero_stealth;
 
    int selection;
    std::cout << "What character would you like to be?:\n(1) Warrior\n(2) Tank\n(3) Wizard\n(4) Healer\n(5) Thief\n";
    std::cin >> selection;

    switch(selection) {
        case 1:
            std::cout << "You are a warrior!\n";
            hero_name = "Warrior";
            hero_health = 100;
            hero_attack = 10;
            hero_defense = 5;
            hero_magic = 1;
            hero_heal = 1;
            hero_stealth = 1;
            break;
        case 2:
            std::cout << "You are a tank!\n";
            hero_name = "Tank";
            hero_health = 100;
            hero_attack = 5;
            hero_defense = 10;
            hero_magic = 1;
            hero_heal = 1;
            hero_stealth = 1;
            break;
        case 3: 
            std::cout << "You are a wizard!\n";
            hero_name = "Wizard";
            hero_health = 100;
            hero_attack = 1;
            hero_defense = 5;
            hero_magic = 10;
            hero_heal = 1;
            hero_stealth = 1;
            break;
        case 4:
            std::cout << "You are a healer!\n";
            hero_name = "Healer";
            hero_health = 100;
            hero_attack = 1;
            hero_defense = 1;
            hero_magic = 5;
            hero_heal = 10;
            hero_stealth = 5;
            break;
        case 5:
            std::cout << "You are a thief!\n";
            hero_name = "Thief";
            hero_health = 100;
            hero_attack = 3;
            hero_defense = 3;
            hero_magic = 1;
            hero_heal = 1;
            hero_stealth = 10;
            break;
        default:
        //Add a custom character selection here later.
            std::cout << "Please make a valid selection!\n";
            HeroSelection();
    }

        Character hero(hero_name, hero_health, hero_attack, hero_defense, hero_magic, hero_heal, hero_stealth);
    
        return hero; 
}            

Character  EnemySelection() {
    //Enemy
    std::string monster_name;
    int monster_health, monster_attack, monster_defense, monster_magic, monster_heal, monster_stealth;
  
    //Get random enemy
    int temp;
    temp =std::rand() % 5;
    std::vector<std::string> enemies = {"Demon", "Orc", "Giant Spider", "Troll", "Dragon"};
    std::string enemy = enemies[temp];
    
    if (enemy.compare("Demon")) {
         std::cout << "You encounter a demon!\n";
         monster_name = "Demon";
         monster_health = 200;
         monster_attack = 15;
         monster_defense = 5;
         monster_magic = 10;
         monster_heal = 1;
         monster_stealth = 1;
     } else if (enemy.compare("Orc")) {
         std::cout << "You encounter an Orc!\n";
         monster_name = "Orc";
         monster_health = 50;
         monster_attack = 5;
         monster_defense = 2;
         monster_magic = 2;
         monster_heal = 1;
         monster_stealth = 1;
     } else if (enemy.compare("Giant Spider")) {
         std::cout << "You encounter a Giant Spider!\n";
         monster_name = "Giant Spider";
         monster_heal = 100;
         monster_attack = 10;
         monster_defense = 5;
         monster_magic = 1;
         monster_heal = 1;
         monster_stealth = 1;
     } else if (enemy.compare("Troll")) {
         std::cout << "You encounter a Troll!\n";
         monster_name = "Troll";
         monster_health = 20;
         monster_attack = 3;
         monster_defense = 3;
         monster_magic = 1;
         monster_heal = 1;
         monster_stealth = 1;
     } else if (enemy.compare("Dragon")) {
         std::cout << "You encounter a Dragon!\n";
         monster_name = "Dragon";
         monster_health = 250;
         monster_attack = 20;
         monster_defense = 7;
         monster_magic = 5;
         monster_heal = 1;
         monster_stealth = 1;
         Character two("Dragon", 250, 20, 7, 5, 0, 0);
     } else {
         std::cout << "Something went wrong..." << std::endl;
     }

     Character monster(monster_name, monster_health, monster_attack, monster_defense, monster_magic, monster_heal, monster_stealth);

     return monster;
}

int main() 
{
    srand(time(NULL));

    Battle::Initiate(HeroSelection(), EnemySelection());


    return 0;
}
