#include <vector> 
#include <ctime> 
#include <numeric> 
#include <math.h> 
#include <cstdio> 
#include <iostream> 
#include <unistd.h>


class Character {
    private: 
        int attack;
        int defense;
        int magic;
        int heal;
        int stealth;
       
    public:
        std::string name;
        //Want to add a weopon type later to affect attack rating. Possibly as
        //another class.
        int health;
  
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

        int Attack() {
            return std::rand() % this -> attack;
        }

        int Defense() {
            return std::rand() % this -> defense;
        }

        int Magic() {
            return std::rand() % this -> magic;
        }

        int Heal() {
            return std::rand() % this -> heal;
        }

        // Add more functions here for other actions. 
};

class Weapon {
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
        static void Initiate(Character& character1, Character& character2) {
            while (true) {
                if (Battle::AttackResult(character1, character2).compare("End of battle!") == 0) {
                    std::cout << "End of battle! \n";
                    break;
                }
            }
        }

        static std::string AttackResult(Character& character1, Character& character2) {
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
                printf("%s has died!\n%s WINS the battle!",
                        character1.name.c_str(),
                        character2.name.c_str());
                return "End of battle!";
            } else if (character2.health == 0) {
                printf("%s has died\n%s WINS the battle!!",
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
/*
void CharacterSelection() { 
    int selection;
    std::cout << "What character would you like to be?:\n(1) Warrior\n(2) Tank\n(3) Wizard\n(4) Healer\n(5) Thief\n";
    std::cin >> selection;

    switch(selection) {
        case 1:
            // name, health, attack, defense, magic, heal, stealth
            std::cout << "You are a warrior!\n";
            Character one("Warrior", 100, 10, 5, 0, 0, 0);
            break;
        case 2:
            std::cout << "You are a tank!\n";
           // return Character one("Tank", 100, 5, 10, 0, 0, 0);
            break;
        case 3: 
            std::cout << "You are a wizard!\n";
            //return Character one("Wizard", 100, 0, 5, 10, 0, 0);
            break;
        case 4:
            std::cout << "You are a healer!\n";
            //return Characterone("Healer", 100, 0, 0, 5, 10, 5);
            break;
        case 5:
            std::cout << "You are a thief!\n";
            //return Character one("Thief", 100, 3, 3, 0, 0, 10);
            break;
        default:
            std::cout << "Please make a valid selection!\n";
            CharacterSelection();
    }
}*/

std::string RandomEnemy() {
    int temp;
    temp =std::rand() % 5;
    std::vector<std::string> enemies = {"Demon", "Orc", "Giant Spider", "Troll", "Dragon"};
    std::string enemy = enemies[temp];

    return enemy;

 /*   switch(enemy) {
        case "Demon":
            std::cout "You encounter a demon!\n";
            return Character two("Demon", 200, 15, 5, 10, 0, 0);
            break;
        case "Orc":
            std::cout "You encounter an Orc!\n";
            return Chracter two("Orc", 50, 5, 2, 2, 0, 0);
            break;
        case "Giant Spider":
            std::cout "You encounter a Giant Spider!\n";
            return Character two("Giant Spider", 100, 10, 5, 0, 0, 0);
            break;
        case "Troll":
            std::cout "You encounter a Troll!\n";
            return Character two("Troll", 30, 3, 3, 0, 0, 0 );
            break;
        case "Dragon":
            std::cout "You encounter a Dragon!\n";
            return Character two("Dragon", 250, 20, 7, 5, 0, 0);
            break;
        default:
            std::cout << "Something went wrong..." <<std::endl;
            RandomEnemy();
    }*/
}

int main() 
{
    srand(time(NULL));
    /*     
    Character one("Warrior", 100, 100, 50, 25, 15, 20);
    Character two("Tank", 200, 30, 175, 10, 30,10);
    

    Battle::Initiate(one, two);
*/
   // CharacterSelection();
    std::string d;
    d = RandomEnemy();

    std::cout << d << std::endl;

   // std::cout << CharacterSelection();
   // Battle::Initiate(CharacterSelection(), RandomEnemy());

    return 0;
}

