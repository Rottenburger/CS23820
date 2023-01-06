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
typedef enum {LETTUCE, SLUG, FROG, EMPTY} type;

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
    double growProb;
    int age;
    int hunger;
    bool isMature;
    int visionDistance;
    int lifespan;
    char displayType;
    type type;
    direction dir;
};

void fillHighBed();
void printHighBed();
void printDisplayType();
int openConfig(int a, char **b);
void movesManager();

#endif //PROJECT_GARDEN_H
