//
// Created by galvanm on 3/31/2026.
//

#include <typeinfo>
#include <iostream>
#include "Map.h"
#include "Room.h"
#include "Creeper.h"
#include "Diamond.h"
#include "Enderman.h"
#include "Ravine.h"
#include "Sword.h"

using std::cout;
using std::endl;

Map::Map() {
    rooms = new Room*[MAP_HEIGHT];
    for (int i = 0; i < MAP_HEIGHT; i++) {
        rooms[i] = new Room[MAP_WIDTH];
    }
    generate_rooms();
    srand(time(0));

    addEntity(new Creeper());
    addEntity(new Diamond());
    addEntity(new Enderman());
    addEntity(new Ravine());
    addEntity(new Enderman());
    addEntity(new Ravine());
    addEntity(new Sword());

    minerCol = 0;
    minerRow = 0;
}
Map::~Map() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        delete[] rooms[i];
    }
    delete[] rooms;
}
void Map::addEntity(Entity* entity) {
    bool placed = false;
    while (!placed) {
        int r = rand() % MAP_HEIGHT;
        int c = rand() % MAP_WIDTH;

        if (rooms[r][c].getEntity() == nullptr) {
            rooms[r][c].setEntity(entity);
            placed = true;
        }
    }
}

void Map::generate_rooms() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            Room* room = &rooms[i][j];
            if (i > 0) {
                room->setNorth(&rooms[i - 1][j]);
            }
            if (i < MAP_HEIGHT - 1) {
                room->setSouth(&rooms[i + 1][j]);
            }
            if (j > 0) {
                room->setWest(&rooms[i][j - 1]);
            }
            if (j < MAP_WIDTH - 1) {
                room->setEast(&rooms[i][j + 1]);
            }
        }
    }
}
void Map::moveMiner(char direction) {
    direction = toupper(direction);
    bool moved = false;

    if (direction == 'N' && minerRow > 0) {
        minerRow--;
        moved = true;
    } else if (direction == 'S' && minerRow < MAP_HEIGHT - 1) {
        minerRow++;
        moved = true;
    } else if (direction == 'E' && minerCol < MAP_WIDTH - 1) {
        minerCol++;
        moved = true;
    } else if (direction == 'W' && minerCol > 0) {
        minerCol--;
        moved = true;
    } else {
        cout << "You bumped into a solid rock wall! You cannot go that way." << endl;
    }

    if (moved) {
        processCurrentRoom();
    }
}

void Map::printWarnings() {
    Room* currentRoom = &rooms[minerRow][minerCol];

    if (currentRoom->getNorth() != nullptr && currentRoom->getNorth()->getEntity() != nullptr) {
        cout << currentRoom->getNorth()->getEntity()->getWarning() << endl;
    }
    if (currentRoom->getSouth() != nullptr && currentRoom->getSouth()->getEntity() != nullptr) {
        cout << currentRoom->getSouth()->getEntity()->getWarning() << endl;
    }
    if (currentRoom->getEast() != nullptr && currentRoom->getEast()->getEntity() != nullptr) {
        cout << currentRoom->getEast()->getEntity()->getWarning() << endl;
    }
    if (currentRoom->getWest() != nullptr && currentRoom->getWest()->getEntity() != nullptr) {
        cout << currentRoom->getWest()->getEntity()->getWarning() << endl;
    }
}
bool Map::isMinerAlive() const {
    return miner.isAlive();
}

bool Map::hasMinerWon() const {
    return miner.hasWon();
}
void Map::printMap() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            Entity* entity = rooms[i][j].getEntity();

            if (entity == nullptr) {
                cout << ". ";
            } else {
                cout << entity->getDisplayChar() << " ";
            }

        }
        cout << endl;
    }
}

void Map::teleportMiner() {
    int newRow, newCol;
    do {
        newRow = rand() % MAP_HEIGHT;
        newCol = rand() % MAP_WIDTH;
    } while (
        (newRow == minerRow && newCol == minerCol) ||
        rooms [newRow][newCol].getEntity() == nullptr);
    minerRow = newRow;
    minerCol = newCol;
    std::cout << "The Enderman teleported you to an empty room!" << std::endl;
}

void Map::processCurrentRoom() {
    Entity* entity = rooms[minerRow][minerCol].getEntity();

    if (entity != nullptr) {
        entity->interact(miner);

        if (dynamic_cast<Enderman*> (entity) != nullptr) {
            teleportMiner();
        }else if (dynamic_cast<Sword*>(entity) != nullptr) {
            rooms[minerRow][minerCol].setEntity(nullptr);
            delete entity;
        } else if (dynamic_cast<Creeper*>(entity) != nullptr) {
            if (miner.isAlive()) {
                rooms[minerRow][minerCol].setEntity(nullptr);
                delete entity;
            }
        }
    }
}