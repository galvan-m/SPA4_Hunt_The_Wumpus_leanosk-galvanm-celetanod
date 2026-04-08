//
// Created by galvanm on 3/31/2026.
//

#include "Sword.h"

#include <iostream>
#include <ostream>

void Sword::interact() {
    std::cout << "You found a sword! This can be used to defend yourself against a Creeper!" << std::endl;
}

std::string Sword::getWarning() const {
    return "You hear a sharp clang of metal against rock!";
}
