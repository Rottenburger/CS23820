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
extern struct organism newLettuce; //TODO change l2 to l
extern struct organism newSlug;
extern struct organism newFrog;
extern struct organism emptySpace;

int row;
int collum;

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

void movesManager() {
    set_random_seed(); //reset seed every move

    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            struct organism directions[8] = {
                    highBed[i][j - 1], highBed[i + 1][j - 1], highBed[i + 1][j],
                    highBed[i + 1][j + 1], highBed[i][j + 1], highBed[i - 1][j + 1],
                    highBed[i - 1][j], highBed[i - 1][j - 1]
            };

            switch (highBed[i][j].type) {
                case LETTUCE:
                    highBed[i][j].age++;
                    double growChance = random0to1();
                    if (highBed[i][j].l.growProb > growChance && highBed[i][j].hasCompletedTurn == false) {
                        highBed[i][j].hasCompletedTurn = true;
                        int growLocation = 0;
                        growLocation = random_range(1, 8);
                        switch (growLocation) {
                            case 1:
                                if (highBed[i][j + 1].type == EMPTY) {
                                    highBed[i][j + 1] = newLettuce; //TODO refactor
                                    highBed[i][j + 1].hasCompletedTurn = true;
                                }
                                break;
                            case 2:
                                if (highBed[i][j - 1].type == EMPTY) {
                                    highBed[i][j - 1] = newLettuce;
                                    highBed[i][j - 1].hasCompletedTurn = true;
                                }
                                break;
                            case 3:
                                if (highBed[i + 1][j].type == EMPTY) {
                                    highBed[i + 1][j] = newLettuce;
                                    highBed[i + 1][j].hasCompletedTurn = true;
                                }
                                break;
                            case 4:
                                if (highBed[i - 1][j].type == EMPTY) {
                                    highBed[i - 1][j] = highBed[i][j];
                                    highBed[i - 1][j].hasCompletedTurn = true;
                                }
                                break;
                            case 5:
                                if (highBed[1 + i][1 + j].type == EMPTY) {
                                    highBed[1 + i][1 + j] = highBed[i][j];
                                    highBed[1 + i][1 + j].hasCompletedTurn = true;
                                }
                                break;
                            case 6:
                                if (highBed[1 - i][1 - j].type == EMPTY) {
                                    highBed[1 - i][1 - j] = highBed[i][j];
                                    highBed[1 - i][1 - j].hasCompletedTurn = true;
                                }
                                break;
                            case 7:
                                if (highBed[1 + i][1 - j].type == EMPTY) {
                                    highBed[1 + i][1 - j] = highBed[i][j];
                                    highBed[1 + i][1 - j].hasCompletedTurn = true;
                                }
                                break;
                            case 8:
                                if (highBed[1 - i][1 + j].type == EMPTY) {
                                    highBed[1 - i][1 + j] = highBed[i][j];
                                    highBed[1 - i][1 + j].hasCompletedTurn = true;
                                }
                                break;
                        }
                    }
                    break;
                case SLUG:
                    highBed[i][j].age++;
                    if (highBed[i][j].s.slugMatureAge < highBed[i][j].age) {


                        if (highBed[i][j].hasCompletedTurn == false) {

                        }
                        break;
                        case FROG:
                            highBed[i][j].age++;
                        if (highBed[i][j].hasCompletedTurn == false) {
                            highBed[i + 1][j] = highBed[i][j];
                            highBed[i + 1][j].hasCompletedTurn = true;
                            highBed[i][j] = emptySpace;
                        }
                        break;
                        case EMPTY:
                            // Move onto next cell
                            break;
                        case WALL:
                            // Move onto next cell
                            break;
                        default:
                            printf("error, there appears to be an undefined cell");
                        break;
                    }
            }

        }
    }
}

//Handles input for number of days to run
int runSimulation(int d) {
    for(int i = 0; i < d; i++) {
        movesManager();
        nextTurn();
    }
    return 0;
}

void nextTurn(){
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            highBed[i][j].hasCompletedTurn = false;
        }
    }
}

void organismManager(){

}

void rounds(){

}

void lettuceMove(){

}

/*int slugMove(direction, int i, int j) {

}*/
