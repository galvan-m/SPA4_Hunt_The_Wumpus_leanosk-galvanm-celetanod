//
// Created by galvanm on 3/31/2026.
//

#ifndef SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_RAVINE_H
#define SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_RAVINE_H
#include "Inhibitor.h"


class Ravine : public Inhibitor {
public:
    void interact() override;
    std::string getWarning() const override;
    bool isFatal() const override;
};


#endif //SPA4_HUNT_THE_WUMPUS_LEANOSK_GALVANM_RAVINE_H