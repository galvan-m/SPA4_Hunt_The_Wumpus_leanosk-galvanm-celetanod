//
// Created by galvanm on 3/31/2026.
//

#ifndef SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_ROOM_H
#define SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_ROOM_H

class Entity;
class Room {
public:
    Room();
    Room(Room* north, Room* south, Room* east, Room* west);

    void setNorth(Room* room);
    void setSouth(Room* room);
    void setEast(Room* room);
    void setWest(Room* room);
    void setEntity(Entity* entity);

    Room* getNorth();
    Room* getSouth();
    Room* getEast();
    Room* getWest();
    Entity* getEntity();
private:
    Room* north;
    Room* south;
    Room* east;
    Room* west;
    Entity* entity;

};


#endif //SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_ROOM_H