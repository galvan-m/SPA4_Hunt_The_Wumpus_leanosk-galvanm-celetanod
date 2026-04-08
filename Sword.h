//
// Created by galvanm on 3/31/2026.
//

#ifndef SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_SWORD_H
#define SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_SWORD_H
#include "Item.h"


class Sword : public Item {
    public:
    void interact() override;
    std::string getWarning() const override;
};


#endif //SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_SWORD_H