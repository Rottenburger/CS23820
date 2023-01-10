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

        .l.growProb = 0.0
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
        .dir = STATIONARY,
        .hasCompletedTurn = false
};

struct organism wall = {
        .type = WALL,
        .displayType = " X ",
        .dir = STATIONARY,
        .hasCompletedTurn = false
};

void fillHighBed(){
    //Fill the highbed will empty structs
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            highBed[i][j] = emptySpace;
        }
    }

    //placeholder TODO

    highBed[11][11] = newLettuce;
    highBed[6][2] = newSlug;
    highBed[5][10] = newSlug;
    highBed[2][6] = newSlug;
    highBed[1][1] = newFrog;
}

void createWalls() {
//Define the walls of the highbed //TODO print numbered grid
    for (int i = 0; i < GARDEN_SIZE; i++) {
        highBed[i][0] = wall;
    }

    for (int i = 0; i < GARDEN_SIZE; i++) {
        highBed[0][i] = wall;
    }

    for (int i = 0; i < GARDEN_SIZE; i++) {
        highBed[i][GARDEN_SIZE-1] = wall;
    }

    for (int i = 0; i < GARDEN_SIZE; i++) {
        highBed[GARDEN_SIZE-1][i] = wall;
    }
};
