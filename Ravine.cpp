//
// Created by galvanm on 3/31/2026.
//
#include <iostream>
#include "Ravine.h"
using std::cout;

void Ravine::interact() {
    std::cout << "You fell into a pit and died! Game over.\n";
}

std::string Ravine::getWarning() const {
    return "You feel a gust of wind...";
}

bool Ravine::isFatal() const {
    return true;
}