//
// Created by Thomas Roethenbaugh on 04/01/2023.
//
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include "garden.h"

/**
 * This structure forms the basis for all the organisms in
 * the simulation. It contains all the paramenters for each
 * type of creature which could get confusing if more creatures
 * or paramenters were added. However, given the minimal number
 * it should be sufficent for now.
 * Varibles include its location, direction, type, display type
 * (used for printing) etc.
 */
struct organism {
    int row;
    int column;
    float growProb;
    int age;
    int hunger;
    bool isMature;
    int visionDistance;
    int lifespan;
    char displayType;
    type type;
    direction dir;
};

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

    highBed[11][11] = l1;
}

void printHighBed() {
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            printf("(%d,%d) = (%d,%d,%c) ", i, j, highBed[i][j].column, highBed[i][j].row, highBed[i][j].displayType);
        }
        printf("\n");
    }
}

void printDisplayType() {
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            printf("%c", highBed[i][j].displayType);
        }
        printf("\n");
    }
}