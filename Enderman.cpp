//
// Created by galvanm on 3/31/2026.
//

#include "Enderman.h"

#include <iostream>
#include <ostream>

void Enderman::interact() {
    std::cout << "You accidently encountered an Enderman and it moved you to a random location!" << std::endl;
}

std::string Enderman::getWarning() const {
    return "You hear grunts...";
}

bool Enderman::isFatal() const {
    return false;
}
