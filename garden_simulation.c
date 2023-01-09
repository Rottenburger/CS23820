//
// Created by Thomas Roethenbaugh on 06/01/2023.
//
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
//extern int day = 0;

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
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            set_random_seed(); //reset seed after every cell
            //printDisplayType(); //Used to print the screen after every cell is checked
            //printAge();
#ifndef DEBUG
            clear_output(); //Makes simulation non-scrolling when run in terminal
#endif //DEBUG
            if (highBed[i][j].hasCompletedTurn == false) { //If completed turn move on

                struct organism directions[8] = { //Hardcoded locations of every neigbouring cell used for slug and lettuce interactions
                        highBed[i][j - 1], highBed[i + 1][j - 1], highBed[i + 1][j],
                        highBed[i + 1][j + 1], highBed[i][j + 1], highBed[i - 1][j + 1],
                        highBed[i - 1][j], highBed[i - 1][j - 1]
                };

                switch (highBed[i][j].type) { //Check type of cell
                    case LETTUCE:
                        highBed[i][j].age++;
                        double growChance = random0to1();
                        if (highBed[i][j].l.growProb > growChance) {
                            highBed[i][j].hasCompletedTurn = true;
                            int growLocation = random_range(1, 8);
                            if (directions[growLocation].type == EMPTY) {
                                directions[growLocation] = newSlug;
                            }
                        }

                        /*switch (growLocation) {
                            case 1:
                                if (directions[0].type == EMPTY) {
                                    directions[0] = newLettuce;
                                    directions[0].hasCompletedTurn = true;
                                }
                                break;
                            case 2:
                                if (directions[1].type == EMPTY) {
                                    directions[1] = newLettuce;
                                    directions[1].hasCompletedTurn = true;
                                }
                                break;
                            case 3:
                                if (directions[2].type == EMPTY) {
                                    directions[2] = newLettuce;
                                    directions[2].hasCompletedTurn = true;
                                }
                                break;
                            case 4:
                                if (directions[3].type == EMPTY) {
                                    directions[3] = newLettuce;
                                    directions[3].hasCompletedTurn = true;
                                }
                                break;
                            case 5:
                                if (directions[4].type == EMPTY) {
                                    directions[4] = newLettuce;
                                    directions[4].hasCompletedTurn = true;
                                }
                                break;
                            case 6:
                                if (directions[5].type == EMPTY) {
                                    directions[5] = newLettuce;
                                    directions[5].hasCompletedTurn = true;
                                }
                                break;
                            case 7:
                                if (directions[6].type == EMPTY) {
                                    directions[6] = newLettuce;
                                    directions[6].hasCompletedTurn = true;
                                }
                                break;
                            case 8:
                                if (directions[7].type == EMPTY) {
                                    directions[7] = newLettuce;
                                    directions[7].hasCompletedTurn = true;
                                }
                                break;
                        }*/
                        break;
                    case SLUG:
                        highBed[i][j].age++; //Increase age of slug
                        if (highBed[i][j].age >= highBed[i][j].s.slugLifespan) { //Kill slug if too old
                            highBed[i][j] = emptySpace;
                            break;
                        }
                        if (highBed[i][j].isMature) { //This handles slug reproduction
                            for (int k = 0; k < 7; k++) {
                                if (directions[k].type == SLUG && directions[k].isMature) {
                                    int slugSpawnLocation = random_range(0, 7);
                                    if (directions[slugSpawnLocation].type == EMPTY) {
                                        directions[slugSpawnLocation] = newSlug;
                                    }
                                }
                            }
                        }
                        for (int l = 0; l < 7; l++) { //This handles eating
                            if (directions[l].type == LETTUCE && highBed[i][j].hasCompletedTurn == false) {
                                directions[l] = emptySpace;
                                directions[l].hasCompletedTurn = true;
                                break;
                            }
                        }
                        if (highBed[i][j].hasCompletedTurn == false) { //This handles movement if not eaten
                            int moveDir = highBed[i][j].dir;
                            directions[moveDir] = highBed[i][j];
                            highBed[i][j] = emptySpace;
                            break;
                        }
                        break;
                    case FROG:
                        highBed[i][j].age++; //Increase age of frog
                        highBed[i][j].f.hunger++; //Increase hunger of frog
                        if (highBed[i][j].age >= highBed[i][j].f.frogLifespan) { //Kill frog if too old
                            highBed[i][j] = emptySpace;
                            break;
                        }
                        if (highBed[i][j].isMature) { //This handles frog reproduction //TODO doesn't work with vision atm
                            for (int k = 0; k < 7; k++) {
                                if (directions[k].type == FROG && directions[k].isMature) {
                                    int slugSpawnLocation = random_range(0, 7);
                                    directions[slugSpawnLocation] = newFrog;
                                }
                            }
                        }
                        //This checks every direction as far as the frog can see, if there's
                        //food the frog will move to that location, removing the slug and reset
                        //the frog's hunger level
                        int range = newFrog.f.visionDistance;
                        for (int l = 1; l <= range; l++) {
                            if (highBed[i][j + l].type == SLUG && highBed[i][j].hasCompletedTurn == false) {
                                highBed[i][j + l].f.hunger = 0;
                                highBed[i][j + l] = highBed[i][j];
                                highBed[i][j + l] = emptySpace;
                                break;
                            }
                        }
                        for (int l = 1; l <= range; l++) {
                            if (highBed[i + l][j].type == SLUG && highBed[i][j].hasCompletedTurn == false) {
                                highBed[i + l][j - l].f.hunger = 0;
                                highBed[i + l][j - l] = highBed[i][j];
                                highBed[i + l][j - l] = emptySpace;
                                break;
                            }
                        }
                        for (int l = 1; l <= range; l++) {
                            if (highBed[i - l][j].type == SLUG && highBed[i][j].hasCompletedTurn == false) {
                                highBed[i - l][j].f.hunger = 0;
                                highBed[i - l][j] = highBed[i][j];
                                highBed[i - l][j] = emptySpace;
                                break;
                            }
                            break;
                        }

                        if (highBed[i][j].hasCompletedTurn == false) { //This handles movement if hungry and no food seen
                            int hopRange = newFrog.f.visionDistance * 2;
                            int randomHop = random_range(1, range);
                            directions[randomHop] = highBed[i][j];
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
        updateOrganismMaturity();
        nextTurn();
        //clear_output(); //Used for terminal simulation
        printDisplayType();
        //day++;
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

void updateOrganismMaturity(){
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {

            if(highBed[i][j].type == SLUG) {
                if (highBed[i][j].s.slugMatureAge < highBed[i][j].age) {
                    highBed[i][j].isMature = true;
                    strcpy(highBed[i][j].displayType, " S ");
                }
            }
            if (highBed[i][j].type == FROG){
                if (highBed[i][j].f.frogMatureAge < highBed[i][j].age) {
                    highBed[i][j].isMature = true;
                    strcpy(highBed[i][j].displayType, " F ");
                }
            }
        }
    }
}

void rounds(){

}

void lettuceMove(){

}

struct organism frogFindFood(int i, int j) {
    /*int range = newFrog.f.visionDistance;

    for (int k = 1; k <= range; k++) {
        if(k.type)
    }

    // Check if the current cell has a neighbor to the south
    for (int i = 1; i <= range; i++) {
        if (row + i < GARDEN_SIZE) {
            neighbor_count++;
        }
    }

    // Check if the current cell has a neighbor to the west
    for (int i = 1; i <= range; i++) {
        if (col - i >= 0) {
            neighbor_count++;
        }
    }

    // Check if the current cell has a neighbor to the east
    for (int i = 1; i <= range; i++) {
        if (col + i < GARDEN_SIZE) {
            neighbor_count++;
        }
    }*/
}

/**
* to clear the terminal to allow for a non-scrolling "animation" of the output.
*/
void clear_output(){
    printf("\e[1;1H\e[2J"); //Using ANSI Escape Sequences (works on many terminals)
//system("clear"); //Mac or Linux
system("cls"); //Windows
//clrscr(); // windows including header file: conio.h
}
