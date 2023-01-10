//
// Created by Thomas Roethenbaugh on 04/01/2023.
//
#include <stdbool.h>
#include "garden.h"

/**
 * This is the 2D array that will contain all of the cells of data
 * and is used to represent the highbed described.
 */
struct organism highBed[GARDEN_SIZE][GARDEN_SIZE];

/**
 * Default parameters of the lettuce for simulation, each new lettuce
 * will use this default struct.
 */
struct organism newLettuce = {
        .type = LETTUCE,
        .displayType = " O ",
        .hasCompletedTurn = false,

        .l.growProb = 0.0
};
/**
 * Default parameters of the slug for simulation, each new slug
 * will use this default struct.
 */
struct organism newSlug = {
        .type = SLUG,
        .displayType = " s ",
        .dir = EAST,
        .hasCompletedTurn = false,

        .s.slugLifespan = 16,
        .s.slugMatureAge = 5,
        .s.slugReproduceProb = 0.9
};
/**
 * Default parameters of the frog for simulation, each new frog
 * will use this default struct.
 */
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
/**
 * Used by the fillHighBed() function to fill the 2D array with
 * 'empty' spaces
 */
struct organism emptySpace = {
        .type = EMPTY,
        .displayType = "   ",
        .dir = STATIONARY,
        .hasCompletedTurn = false
};
/**
 * Used by the createWalls() function to correctly display walls
 * around the highbed. It also helps organisms within the simulation
 * not go out of bounds.
 */
struct organism wall = {
        .type = WALL,
        .displayType = " X ",
        .dir = STATIONARY,
        .hasCompletedTurn = false
};

/**
 * Fills the highbed with 'empty' structs to allow the organisms in
 * the simulation to know if there is an empty space they can move into.
 * It also fills it with the organisms used for simulation.
 */
void fillHighBed(){
    //Fill the highbed will empty structs
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            highBed[i][j] = emptySpace;
        }
    }

    //placeholder TODO At the moment the organisms used for simulation are hardcoded

    highBed[11][11] = newLettuce;
    highBed[6][2] = newSlug;
    highBed[5][10] = newSlug;
    highBed[2][6] = newSlug;
    highBed[1][1] = newFrog;
}

/**
 * This defines the walls of the highbed, ensuring the organisms in the
 * simulation don't go out of bounds.
 */
void createWalls() {
//Define the walls of the highbed
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
