//
// Created by Thomas Roethenbaugh on 04/01/2023.
//
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include "garden.h"

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

struct organism highBed[GARDEN_SIZE][GARDEN_SIZE];


/*void initDynamicArray() {
    highBed = malloc(GARDEN_SIZE * sizeof(struct organism *));

    for (int i = 0; i < GARDEN_SIZE; i++) {
        highBed[i] = malloc(GARDEN_SIZE * sizeof(struct organism));
    }
}

void freeMemoryHighBed() {
    for (int i = 0; i < GARDEN_SIZE; i++) {
        free(highBed[i]);
    }
    free(highBed);
}*/

void fillHighBed(){
    struct organism l1;
    l1.type = LETTUCE;
    l1.column = 11;
    l1.row = 11;

    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            highBed[i][j].column = i;
            highBed[i][j].row = j;
        }
    }

    highBed[11][11] = l1;

}

void printHighBed() {

    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            printf("(%d,%d) = (%d,%d)\n", i, j, highBed[i][j].column, highBed[i][j].row);
        }
    }
}