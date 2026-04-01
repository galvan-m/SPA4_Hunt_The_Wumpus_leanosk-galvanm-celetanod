//
// Created by galvanm on 3/29/2026.
//

#include <iostream>
#include "Map.h"

using std::cout;
using std::cin;
using std::endl;

void help();


int main() {
    Map* map = new Map();

    help();

    map->printMap();
}

void help() {
    cout << "Welcome to the Shimmering Mines!\n\n"
    "Here you are an adventurer on a search for some valuable diamonds hidden\n"
    "deep within the mine. Beware for there are dangers in this mine! Creepers\n"
    "linger around, self-exploding when you get too close, and there are ravines\n"
    "where you will fall to your death. Do not worry, you can defend yourself\n"
    "from Creepers using swords found in the mine. Enderman also spend time in\n"
    "the mine, though they are shy creatures that value their solitude, so getting\n"
    "near one will result in it randomly teleporting you somewhere else within the\n"
    "mine.\n\n"

    "Look out for these hints to dodge the hazards, locate tools that can help,\n"
    "and locate the diamond: \n"
    " - You will smell gundpowder when a Creeper is nearby\n"
    " - You will feel gust of wind when a ravine is nearby\n"
    " - You will hear grunts when close to an Enderman\n"
    " - You will hear a sharp clang of metal against rock when near a sword\n"
    " - You will see a glint of light shining off a diamond when you are near one\n"
    << endl;
}