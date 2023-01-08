//
// Created by Thomas Roethenbaugh on 04/01/2023.
//
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include "garden.h"
#include <time.h>
#include <string.h>

/**
 * This is the 2D array that will contain all of the cells of data
 * and is used to represent the highbed described.
 */
struct organism highBed[GARDEN_SIZE][GARDEN_SIZE];

struct organism newLettuce = {
        .type = LETTUCE,
        .displayType = " O ",
        .hasCompletedTurn = false,

        .l.growProb = 0.8
};

struct organism newSlug = {
        .type = SLUG,
        .displayType = " s ",
        .dir = EAST,
        .hasCompletedTurn = false,

        .s.slugLifespan = 16,
        .s.slugMatureAge = 5,
        .s.slugReproduceProb = 0.9
};

struct organism newFrog = {
        .type = FROG,
        .displayType = " f ",
        .dir = STATIONARY,
        .hasCompletedTurn = false,

        .f.visionDistance = 2,
        .f.frogLifespan = 20,
        .f.frogMatureAge = 5,
        .f.frogReproduceProb = 0.0
};

struct organism emptySpace = {
        .type = EMPTY,
        .displayType = "   ",
        .dir = STATIONARY
};

struct organism wall = {
        .type = WALL,
        .displayType = " X ",
        .dir = STATIONARY
};

void fillHighBed(){
    //Fill the highbed will empty structs
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            highBed[i][j] = emptySpace;
        }
    }

    //placeholder TODO
/*    struct organism lettuce;*/
    /*lettuce.type = LETTUCE;
    strcpy(lettuce.displayType, " O ");
    lettuce.column = 11;
    lettuce.row = 11;
    lettuce.growProb = 0.8;*/

    highBed[5][5] = newLettuce;
    highBed[6][7] = newSlug;
    highBed[2][5] = newFrog;
}

void createWalls() {
//Define the walls of the highbed //TODO print numbered grid
    for (int i = 0; i < GARDEN_SIZE; i++) {
        char a[3];
        sprintf(a, "%d", i);
        strcpy(highBed[i][0].displayType, " X ");
        highBed[i][0].type = WALL;
    }

    for (int i = 0; i < GARDEN_SIZE; i++) {
        char a[3];
        sprintf(a, "%d", i);
        strcpy(highBed[0][i].displayType, " X ");
        highBed[0][i].type = WALL;
    }

    for (int i = 0; i < GARDEN_SIZE; i++) {
        char a[3];
        sprintf(a, "%d", i);
        strcpy(highBed[i][GARDEN_SIZE-1].displayType, " X ");
        highBed[i][GARDEN_SIZE-1].type = WALL;
    }

    for (int i = 0; i < GARDEN_SIZE; i++) {
        char a[3];
        sprintf(a, "%d", i);
        strcpy(highBed[GARDEN_SIZE-1][i].displayType, " X ");
        highBed[GARDEN_SIZE-1][i].type = WALL;
    }
};
