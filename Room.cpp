//
// Created by galvanm on 3/31/2026.
//

#include "Room.h"

Room::Room(Room *north, Room *south, Room *east, Room *west) {
    this->north = north;
    this->south = south;
    this->west = west;
    this->east = east;
    entity = nullptr;
}

Room::Room() {
    north = nullptr;
    south = nullptr;
    west = nullptr;
    east = nullptr;
    entity = nullptr;
}
void Room::setNorth(Room* room) {
    this->north = room;
}
void Room::setEast(Room *room) {
    this->east = room;
}
void Room::setWest(Room *room) {
    this->west = room;
}

void Room::setSouth(Room *room) {
    this->south = room;
}
void Room::setEntity(Entity* entity) {
    this->entity = entity;
}
Room* Room::getNorth() {
    return north;
}
Room* Room::getSouth() {
    return south;
}
Room* Room::getEast() {
    return east;
}
Room* Room::getWest() {
    return west;
}
Entity* Room::getEntity() {
    return entity;
}


