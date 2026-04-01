//
// Created by galvanm on 3/31/2026.
//

#include <typeinfo>
#include "Map.h"

#include <iostream>

#include "Player.h"
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
}
Map::~Map() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        delete[] rooms[i];
    }
    delete[] rooms;
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

void Map::printMap() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            Room* room = &rooms[i][j];
            if (typeid(room->getEntity()) == typeid(Player)) {
                cout << "P ";
            } else if (typeid(room->getEntity()) == typeid(Enderman)) {
                cout << "E ";
            } else if (typeid(room->getEntity()) == typeid(Ravine)) {
                cout << "R ";
            } else if (typeid(room->getEntity()) == typeid(Sword)) {
                cout << "S ";
            } else if (typeid(room->getEntity()) == typeid(Creeper)) {
                cout << "C ";
            } else if (typeid(room->getEntity()) == typeid(Diamond)) {
                cout << "D ";
            } else if (room->getEntity() == nullptr) {
                cout << ". ";
            }

        }
        cout << endl;
    }
}