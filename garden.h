//
// Created by Thomas Roethenbaugh on 30/11/2022.
//

#ifndef PROJECT_GARDEN_H
#define PROJECT_GARDEN_H

#define GARDEN_SIZE 12

typedef enum {NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST, NORTH_WEST, STATIONARY} direction;
typedef enum {LETTUCE, SLUG, FROG, EMPTY} type;

struct organism;

void fillHighBed();
void initDynamicArray();
void printHighBed();
void printOnlyChar();
void freeMemoryHighBed();

#endif //PROJECT_GARDEN_H
