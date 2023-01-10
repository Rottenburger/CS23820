/*
C & C++ module assignment by Thomas Roethenbaugh 11/12/2022
*/
#include <stdio.h>
#include "garden.h"
#include <stdbool.h>
bool movesMode = false;

int main() {
    printf("Welcome to highbed simulator!\n");
    char configName;
    char mode;
    int numOfSim = 0;
    printf("Which config file do you want to use?\n");
    //scanf("%s", &configName); //load config
    printf("Run simulation in rounds mode or moves mode?\n"
           "Type r or m for desired mode (MUST BE LOWERCASE!)\n");
    scanf("%s", &mode); //load desired mode
    printf("How many rounds of simulation do you want to run?\n");
    scanf("%d", &numOfSim); //num of simulations
    fillHighBed();
    createWalls();
    if(mode == 'r'){
        runSimulation(numOfSim);
        printf("\nHighbed simulator end!\n");
        return 0;
    }
    if(mode == 'm'){
        movesMode = true;
        runSimulation(numOfSim);
        printf("\nHighbed simulator end!\n");
        return 0;
    }
    printf("\nHighbed simulator ended incorrectly\n");
    return 1;
}
