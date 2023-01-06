//
// Created by Thomas Roethenbaugh on 06/01/2023.
//
#include "garden.h"
//THIS WILL PRINT THE MATRIX
void printHighBed() {
int row, columns;
for (row=0; row<10; row++)
{
    for(columns=0; columns<10; columns++)
    {
        printf("%d ", highBed[row][columns]);
    }
    printf("\n");
}
}