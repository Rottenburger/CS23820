/*
 Created by Thomas Roethenbaugh on 06/01/2023.
 This file was created to handle all the functions
 involved with displaying the simulation to the user.
*/

#include <stdio.h>
#include "garden.h"

extern struct organism highBed[GARDEN_SIZE][GARDEN_SIZE];

void printHighBed() {
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            printf("(%d,%d) = (%d,%d,%s) ", i, j, highBed[i][j].column, highBed[i][j].row, highBed[i][j].displayType);
        }
        printf("\n");
    }
}

void printDisplayType() {
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            printf("%s", highBed[i][j].displayType);
        }
        printf("\n");
    }
}
