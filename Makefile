
SPA4: main.o Creeper.o Diamond.o Enderman.o Entity.o Inhibitor.o Item.o Map.o Miner.o Ravine.o Room.o Sword.o
	g++ -Wall -g -o SPA4 main.o Creeper.o Diamond.o Enderman.o Entity.o Inhibitor.o Item.o Map.o Miner.o Ravine.o Room.o Sword.o


main.o: main.cpp
	g++ -Wall -g -c main.cpp

Creeper.o: Creeper.cpp Creeper.h
	g++ -Wall -g -c Creeper.cpp

Diamond.o: Diamond.cpp Diamond.h
	g++ -Wall -g -c Diamond.cpp

Enderman.o: Enderman.cpp Enderman.h
	g++ -Wall -g -c Enderman.cpp

Entity.o: Entity.cpp Entity.h
	g++ -Wall -g -c Entity.cpp

Inhibitor.o: Inhibitor.cpp Inhibitor.h
	g++ -Wall -g -c Inhibitor.cpp

Item.o: Item.cpp Item.h
	g++ -Wall -g -c Item.cpp

Map.o: Map.cpp Map.h
	g++ -Wall -g -c Map.cpp

Miner.o: Miner.cpp Miner.h
	g++ -Wall -g -c Miner.cpp

Ravine.o: Ravine.cpp Ravine.h
	g++ -Wall -g -c Ravine.cpp

Room.o: Room.cpp Room.h
	g++ -Wall -g -c Room.cpp

Sword.o: Sword.cpp Sword.h
	g++ -Wall -g -c Sword.cpp


clean:
	rm -f main.o Creeper.o Diamond.o Enderman.o Entity.o Inhibitor.o Item.o Map.o Miner.o Ravine.o Room.o Sword.o SPA4