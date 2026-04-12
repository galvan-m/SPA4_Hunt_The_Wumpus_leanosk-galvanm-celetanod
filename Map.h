//
// Created by galvanm on 3/31/2026.
//

#ifndef SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_MAP_H
#define SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_MAP_H
#include "Entity.h"
#include "Miner.h"

class Room;
constexpr int MAP_HEIGHT = 6;
constexpr int MAP_WIDTH = 6;

class Map {
public:
    Map();
    ~Map();
    void addEntity(Entity *entity);
    void printMap();
    void teleportMiner();
    void moveMiner(char direction);
    void printWarnings();
    bool isMinerAlive() const;
    bool hasMinerWon() const;

private:
    void generate_rooms();
    void processCurrentRoom();
    Room** rooms;
    Miner miner;
    int minerRow;
    int minerCol;
};


#endif //SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_MAP_H