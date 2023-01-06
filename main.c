#include <stdio.h>
#include <stdbool.h>
#include "garden.h"

int main() {
    printf("Garden Paradise Start\n");

    int day = 0; //Timer for each round of the simulation

    //PSEODOCODE
    /*
     * Create 2D array (matrix) to contain the map
     * fill said map with elements (Structs) of plants
     * and animals.
     * Make it randomised using a seed and config files
     * This means your program will need to be able to
     * scan text files.
     * https://stackoverflow.com/questions/54475287/trying-to-change-element-in-2d-array-in-c
     */

    //initDynamicArray();
    fillHighBed();
    //printHighBed();
    printOnlyChar();
    //freeMemoryHighBed();

    printf("Garden Paradise End\n");
    return 0;
}
