//
// Created by galvanm on 3/31/2026.
//

#ifndef SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_ENTITY_H
#define SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_ENTITY_H
#include <string>



class Entity {
public:
    virtual ~Entity() {}

    // Interaction for when Miner comes across it
    virtual void interact() = 0;

    // Warnings/hints for nearby rooms
    virtual std::string getWarning() const = 0;
};


#endif //SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_ENTITY_H