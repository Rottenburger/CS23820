//
// Created by Thomas Roethenbaugh on 04/01/2023.
//
#include "garden.h"

//TODO You are here, need struct that can be used for 2d grid
/* 2D array declaration*/
struct lettuce highBed[12][12] = {
        //{1}, {5}
};

struct lettuce {
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
};

struct frog {
    int row;
    int column;
    int age;
    int hunger;
    char type;
    int matureAge;
    int visionDistance;
    int lifespan;
    DIRECTION direction;
};

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
};