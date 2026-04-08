//
// Created by galvanm on 3/31/2026.
//

#include "Diamond.h"

#include <iostream>
#include <ostream>

void Diamond::interact() {
    std::cout << "You found the diamond! Congratulations!!" << std::endl;
}

std::string Diamond::getWarning() const {
    return "You see a glint of light shining off a diamond!";
}
