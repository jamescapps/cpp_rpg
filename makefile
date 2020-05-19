rpg: main.o battle.o character_selection.o character.o weapon.o
	g++ main.o battle.o character_selection.o character.o weapon.o -o rpg

main.o: main.cpp
	g++ -c main.cpp

battle.o: ./src/battle.cpp
	g++ -c ./src/battle.cpp

character_selection.o: ./src/character_selection.cpp
	g++ -c ./src/character_selection.cpp

character.o: ./src/character.cpp
	g++ -c ./src/character.cpp

weapon.o: ./src/weapon.cpp
	g++ -c ./src/weapon.cpp

clean:
	rm *.o rpg