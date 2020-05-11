#include <vector> 
#include <ctime> 
#include <numeric> 
#include <math.h> 
#include <cstdio> 
#include <iostream> 
#include <unistd.h>



//Current issues.
//Dealing negative damage and not stopping when health gets to zero.
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
            int char1_damage = ceil(char2_attack - char1_defense);
            character1.health = character1.health - char1_damage;

            int char2_damage = ceil(char1_attack - char2_defense);
            character2.health = character2.health -char2_damage; 

            printf("%s attacks %s and deals %d damage\n",
                    character1.name.c_str(),
                    character2.name.c_str(),
                    char2_damage); 

            usleep(20000);
             
            printf("%s attacks %s and deals %d damage\n",
                    character2.name.c_str(),
                    character1.name.c_str(),
                    char1_damage);

            usleep(200000);

            printf("%s health: %d\n %s health: %d\n",
                    character1.name.c_str(),
                    character1.health,
                    character2.name.c_str(),
                    character2.health);
            
            usleep(200000);

            if (character1.health < 0) {
                character1.health = 0;
            }

            if (character2.health < 0) {
                character2.health = 0;
            }

            if (character1.health == 0) {
                printf("%s has died!\n %s WINS the battle!",
                        character1.name.c_str(),
                        character2.name.c_str());
                return "End of battle!";
            } else {
                return "rematch!!";
            }

            if (character2.health == 0) {
                printf("%s has died\n %s WINS the battle!!",
                        character2.name.c_str(),
                        character1.name.c_str());
                
                return "End of battle!";
            } else {
                return "rematch!!";
            }

        }
};

int main() 
{
    srand(time(NULL));
         
    Character one("Warrior", 100, 100, 50, 25, 15, 20);
    Character two("Tank", 200, 30, 175, 10, 30,10);

    Battle::Initiate(one, two);

    return 0;
}
