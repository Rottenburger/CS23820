/*
C & C++ module assignment by Thomas Roethenbaugh 11/12/2022
*/

#include <stdio.h>
#include <stdbool.h>
#include "garden.h"

int main() {
    printf("Welcome to highbed simulator!\n");

    //int day = 0; //Timer for each round of the simulation

    fillHighBed();
    movesManager();
    printDisplayType();

    //print all struct data on the highbed //TODO
#ifndef DEBUG

#endif //DEBUG

    printf("Highbed simulator end!\n");
    return 0;
}
