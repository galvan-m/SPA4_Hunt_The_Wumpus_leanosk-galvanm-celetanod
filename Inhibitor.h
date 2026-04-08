//
// Created by galvanm on 3/31/2026.
//

#ifndef SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_INHIBITOR_H
#define SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_INHIBITOR_H
#include "Entity.h"


class Inhibitor : public Entity {
    public:
    virtual bool isFatal() const = 0;
};


#endif //SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_INHIBITOR_H