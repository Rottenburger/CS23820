//
// Created by Thomas Roethenbaugh on 04/01/2023.
//
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include "garden.h"
#include <time.h>

/**
 * This is the 2D array that will contain all of the cells of data
 * and is used to represent the highbed described.
 */
struct organism highBed[GARDEN_SIZE][GARDEN_SIZE];

void fillHighBed(){
    //Fill the highbed will empty structs
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            highBed[i][j].column = i;
            highBed[i][j].row = j;
            highBed[i][j].growProb = 0;
            highBed[i][j].age = 0;
            highBed[i][j].hunger = 0;
            highBed[i][j].isMature = false;
            highBed[i][j].visionDistance = 0;
            highBed[i][j].lifespan = 0;
            highBed[i][j].displayType = 'O';
            highBed[i][j].type = EMPTY;
            highBed[i][j].dir = STATIONARY;
        }
    }

    //placeholder TODO
    struct organism l1;
    l1.type = LETTUCE;
    l1.displayType = 'l';
    l1.column = 11;
    l1.row = 11;
    l1.growProb = 0.8;

    highBed[5][5] = l1;
}