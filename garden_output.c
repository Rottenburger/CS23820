/*
 Created by Thomas Roethenbaugh on 06/01/2023.
 This file was created to handle all the functions
 involved with displaying the simulation to the user.
*/

#include <stdio.h>
#include "garden.h"

/**
 * 2D grid variable containing all the data to printed
 */
extern struct cell highBed[GARDEN_SIZE][GARDEN_SIZE];

/**
 * These are alternative methods that I used for printing other information about
 * each cell in order to debug my program.
 */
#ifndef DEBUG
void printHighBed() {
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            printf("(%d,%d) = (%d,%s) ", i, j, highBed[i][j].age, highBed[i][j].displayType);
        }
        printf("\n");
    }
}

void printAge() {
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            printf("%d", highBed[i][j].age);
        }
        printf("\n");
    }
}
#endif //DEBUG

/**
 * Prints every cells age to the terminal
 */
void printAge() {
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            printf(" %d ", highBed[i][j].age);
        }
        printf("\n");
    }
    printf("\n");
}
/**
 * Prints the symbols used for viewing the simulation
 */
void printDisplayType() {
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            printf("%s", highBed[i][j].displayType);
        }
        printf("\n");
    }
}
