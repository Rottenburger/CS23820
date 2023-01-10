/*
C & C++ module assignment by Thomas Roethenbaugh 11/12/2022
*/

#include <stdio.h>
#include "garden.h"

int main() {
    printf("Welcome to highbed simulator!\n");
    char configName;
    printf("Which config file do you want to use?\n");
    //scanf("%s", &configName); //load config
    printf("Run simulation in rounds mode or moves mode?\n"
           "Type R or M for desired mode\n");
    //scanf("%s", &mode); //load desired mode

    fillHighBed();
    createWalls();
    //movesManager();
    runSimulation(10);
    printAge();
    //printDisplayType();
    //openConfig();
    //readConfigData();

    //print all struct data on the highbed
#ifndef DEBUG
    printHighBed();
#endif //DEBUG

    printf("\nHighbed simulator end!\n");
    return 0;
}
