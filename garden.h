//
// Created by Thomas Roethenbaugh on 30/11/2022.
//

#ifndef PROJECT_GARDEN_H
#define PROJECT_GARDEN_H
#define DEBUG

#define GARDEN_SIZE 12
#define BUFFER_SIZE 1024

#include <stdbool.h>

typedef enum {NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST, NORTH_WEST, STATIONARY} direction;
typedef enum {LETTUCE, SLUG, FROG, EMPTY, WALL} type;

struct lettuce {
    double growProb;
};

struct slug {
    double slugReproduceProb;
    int slugLifespan;
    int slugMatureAge;
};

struct frog {
    double frogReproduceProb;
    int frogLifespan;
    int frogMatureAge;
    int visionDistance;
};

/**
 * This structure forms the basis for all the organisms in
 * the simulation. It contains all the paramenters for each
 * type of creature which could get confusing if more creatures
 * or paramenters are added. However, given the minimal number
 * it should be sufficent for now.
 * Varibles include its location, direction, type, display type
 * (used for printing) etc.
 */
struct organism {
    int row;
    int column;
    int age;
    bool isMature;
    bool hasCompletedTurn;
    type type;
    direction dir;
    char displayType[3];

    struct lettuce l;
    struct slug s;
    struct frog f;
};

void fillHighBed();
void printHighBed();
void printDisplayType();
void openConfig();
void movesManager();
void createWalls();
int runSimulation(int i);
void nextTurn();

#endif //PROJECT_GARDEN_H
