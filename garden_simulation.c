//
// Created by Thomas Roethenbaugh on 06/01/2023.
//
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "garden.h"
#include <time.h>
#include <string.h>
extern struct organism highBed[GARDEN_SIZE][GARDEN_SIZE];
extern struct organism lettuce; //TODO change l2 to l

/**
* set the random number seed to produce unpredictable random sequences
* note: need #include <time.h>
*/
void set_random_seed(){
    time_t t = time(0); // time is constantly changing and makes a good seed
    srand(t);
}

/**
* get a random integer within a specified range
* note simple, but technically an extremely slight numerical distribution bias.
* @param first - the smallest value that can be returned
* @param last - the largest values that can be returned
* @return a random value between first and last (inclusive)
*/
int random_range(int first, int last){
    return ((rand() % (last-first+1)) + first);
}
/**
* @return - a random number between 0 and 1
*/
double random0to1(){
    return ((double)rand())/RAND_MAX;
}

/*bool isWall(int i, int j, direction dir) {
    int neighbors[4][2] = {{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}};
    for (int k = 0; k < 4; k++) {
        if(neighbors[k][k].)
    }

        return 0;
    return 1;
}*/

void movesManager(){
    set_random_seed(); //reset seed every move
    double growChance = 0;
    int growLocation = 0;

    //Used for checking neighbours on 2D grid
    int offsetx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int offsety[] = {-1, -1, 0, 1, 1, 1, 0, -1};

    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            switch (highBed[i][j].type) {
                case 0: //LETTUCE
                    highBed[i][j].age++;
                    growChance = random0to1();
                    if(highBed[i][j].growProb > growChance && 0 < highBed[i][j].age){
                        growLocation = random_range(1, 4);
                        switch (growLocation) {
                            case 1:
                                if(highBed[i][j+1].type != WALL){
                                    highBed[i][j+1] = lettuce;
                                }
                                break;
                            case 2:
                                if(highBed[i][j-1].type != WALL){
                                    highBed[i][j-1] = lettuce;
                                }
                                break;
                            case 3:
                                if(highBed[i+1][j].type != WALL){
                                    highBed[i+1][j] = lettuce;
                                }
                                break;
                            case 4:
                                if(highBed[i-1][j].type != WALL){
                                    highBed[i-1][j] = lettuce;
                                }
                                break;
                        }
                    }
                    break;
                case 1: //SLUG
                    highBed[i][j].age++;

                    break;
                case 2: //FROG
                    highBed[i][j].age++;
                    break;
                case 3: //EMPTY
                    // Move onto next cell
                    break;
                case 4: //WALL
                    // Move onto next cell
                    break;
                default:
                    printf("error, there appears to be an undefined cell");
                    break;
            } 
        }

    }
}

//Handles input for number of days to run
int runSimulation(int d) {
    for(int i = 0; i < d; i++) {
        movesManager();
    }
    return 0;
}

void organismManager(){

}

void rounds(){

}

void lettuceMove(){

}
