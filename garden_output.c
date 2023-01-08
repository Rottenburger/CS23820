/*
 Created by Thomas Roethenbaugh on 06/01/2023.
 This file was created to handle all the functions
 involved with displaying the simulation to the user.
*/

#include <stdio.h>
#include "garden.h"

extern struct organism highBed[GARDEN_SIZE][GARDEN_SIZE];
//extern int day;

#ifndef DEBUG
void printHighBed() {
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            printf("(%d,%d) = (%d,%s) ", i, j, highBed[i][j].age, highBed[i][j].displayType);
        }
        printf("\n");
    }
}
#endif //DEBUG

void printDisplayType() {
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            printf("%s", highBed[i][j].displayType);
        }
        //printf("%d\n", day);
        printf("\n");
    }
}
