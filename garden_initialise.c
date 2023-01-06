//
// Created by Thomas Roethenbaugh on 04/01/2023.
//
#include <malloc.h>
#include <stdbool.h>
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

struct organism **highBed;


void dynamicArray() {
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
}

/*struct lettuce {
    int row;
    int column;
    float growProb;
    char type;
};

struct slug {
    int row;
    int column;
    int age;
    int hunger;
    char type;
    int lifespan;
    DIRECTION direction;
};*/

/*
void initialiseLettuce(){
    struct lettuce l1;
    l1.growProb = 1;
    l1.row = 1;
    l1.column = 1;
    l1.type = 'O';

}

void fillHighbed(){
    struct lettuce l1;
    highBed[11][11] = l1;
};*/