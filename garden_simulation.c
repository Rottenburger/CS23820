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
            int growLocation = 0;
            int slugSpawnLocation = 0;
            int frogSpawnLocation = 0;

            struct organism directions[8] = { //Hardcoded locations of every neigbouring cell used for slug and lettuce interactions
                    highBed[i][j - 1], highBed[i + 1][j - 1], highBed[i + 1][j],
                    highBed[i + 1][j + 1], highBed[i][j + 1], highBed[i - 1][j + 1],
                    highBed[i - 1][j], highBed[i - 1][j - 1]
            };
            //printDisplayType(); //Used to print the screen after every cell is checked
            //printAge();
#ifndef DEBUG
            clear_output(); //Makes simulation non-scrolling when run in terminal
#endif //DEBUG
            if (highBed[i][j].hasCompletedTurn == false) { //If completed turn move on

                switch (highBed[i][j].type) { //Check type of cell
                    case LETTUCE:
                        highBed[i][j].age++;
                        double growChance = random0to1();
                        highBed[i][j].hasCompletedTurn = true;
                        if (highBed[i][j].l.growProb > growChance) {
                            if (highBed[i][j - 1].type == EMPTY) {
                                highBed[i][j - 1] = newLettuce;
                                highBed[i][j - 1].hasCompletedTurn = true;
                                break;
                            }
                            if (highBed[i + 1][j - 1].type == EMPTY) {
                                highBed[i + 1][j - 1] = newLettuce;
                                highBed[i + 1][j - 1].hasCompletedTurn = true;
                                break;
                            }
                            if (highBed[i + 1][j].type == EMPTY) {
                                highBed[i + 1][j] = newLettuce;
                                highBed[i + 1][j].hasCompletedTurn = true;
                                break;
                            }
                            if (highBed[i + 1][j + 1].type == EMPTY) {
                                highBed[i + 1][j + 1] = newLettuce;
                                highBed[i + 1][j + 1].hasCompletedTurn = true;
                                break;
                            }
                            if (highBed[i][j + 1].type == EMPTY) {
                                highBed[i][j + 1] = newLettuce;
                                highBed[i][j + 1].hasCompletedTurn = true;
                                break;
                            }
                            if (highBed[i - 1][j + 1].type == EMPTY) {
                                highBed[i - 1][j + 1] = newLettuce;
                                highBed[i - 1][j + 1].hasCompletedTurn = true;
                                break;
                            }
                            if (highBed[i - 1][j].type == EMPTY) {
                                highBed[i - 1][j] = newLettuce;
                                highBed[i - 1][j].hasCompletedTurn = true;
                                break;
                            }
                            if (highBed[i - 1][j - 1].type == EMPTY) {
                                highBed[i - 1][j - 1] = newLettuce;
                                highBed[i - 1][j - 1].hasCompletedTurn = true;
                                break;
                            }
                        }
                        break;
                    case SLUG:
                        highBed[i][j].age++; //Increase age of slug
                        if (highBed[i][j].age >= highBed[i][j].s.slugLifespan) { //Kill slug if too old
                            highBed[i][j] = emptySpace;
                            break;
                        }
                        //This handles eating
                        if (highBed[i][j].hasCompletedTurn == false) {
                            if (highBed[i][j + 1].type == LETTUCE && highBed[i][j].hasCompletedTurn == false) {
                                highBed[i][j + 1] = emptySpace;
                                highBed[i][j].hasCompletedTurn = true;
                                break;
                            }
                            if (highBed[i][j - 1].type == LETTUCE && highBed[i][j].hasCompletedTurn == false) {
                                highBed[i][j - 1] = emptySpace;
                                highBed[i][j].hasCompletedTurn = true;
                                break;
                            }
                            if (highBed[i + 1][j - 1].type == LETTUCE && highBed[i][j].hasCompletedTurn == false) {
                                highBed[i + 1][j - 1] = emptySpace;
                                highBed[i][j].hasCompletedTurn = true;
                                break;
                            }
                            if (highBed[i - 1][j + 1].type == LETTUCE && highBed[i][j].hasCompletedTurn == false) {
                                highBed[i - 1][j + 1] = emptySpace;
                                highBed[i][j].hasCompletedTurn = true;
                                break;
                            }
                            if (highBed[i - 1][j].type == LETTUCE && highBed[i][j].hasCompletedTurn == false) {
                                highBed[i - 1][j] = emptySpace;
                                highBed[i][j].hasCompletedTurn = true;
                                break;
                            }
                            if (highBed[i + 1][j].type == LETTUCE && highBed[i][j].hasCompletedTurn == false) {
                                highBed[i + 1][j] = emptySpace;
                                highBed[i][j].hasCompletedTurn = true;
                                break;
                            }
                        }
                        if (highBed[i][j].isMature) { //This handles slug reproduction
                            for (int k = 0; k < 7; k++) {
                                if (directions[k].type == SLUG && directions[k].isMature) {
                                    slugSpawnLocation = random_range(0, 7);
                                    int slugSpawnDir = random_range(NORTH, WEST);
                                    switch (slugSpawnLocation) {
                                        case 0:
                                            if (directions[slugSpawnLocation].type == EMPTY) {
                                                highBed[i][j - k] = newSlug;
                                                highBed[i][j - k].dir = slugSpawnDir;
                                                highBed[i][j - k].hasCompletedTurn = true;
                                                highBed[i][j].hasCompletedTurn = true;
                                            }
                                            break;
                                        case 1:
                                            if (directions[slugSpawnLocation].type == EMPTY) {
                                                highBed[i + k][j - k] = newSlug;
                                                highBed[i + k][j - k].dir = slugSpawnDir;
                                                highBed[i + k][j - k].hasCompletedTurn = true;
                                                highBed[i][j].hasCompletedTurn = true;
                                            }
                                            break;
                                        case 2:
                                            if (directions[slugSpawnLocation].type == EMPTY) {
                                                highBed[i + k][j] = newSlug;
                                                highBed[i + k][j].dir = slugSpawnDir;
                                                highBed[i + k][j].hasCompletedTurn = true;
                                                highBed[i][j].hasCompletedTurn = true;
                                            }
                                            break;
                                        case 3:
                                            if (directions[slugSpawnLocation].type == EMPTY) {
                                                highBed[i + k][j + k] = newSlug;
                                                highBed[i + k][j + k].dir = slugSpawnDir;
                                                highBed[i + k][j + k].hasCompletedTurn = true;
                                                highBed[i][j].hasCompletedTurn = true;
                                            }
                                            break;
                                        case 4:
                                            if (directions[slugSpawnLocation].type == EMPTY) {
                                                highBed[i][j + k] = newSlug;
                                                highBed[i][j + k].dir = slugSpawnDir;
                                                highBed[i][j + k].hasCompletedTurn = true;
                                                highBed[i][j].hasCompletedTurn = true;
                                            }
                                            break;
                                        case 5:
                                            if (directions[slugSpawnLocation].type == EMPTY) {
                                                highBed[i - k][j + k] = newSlug;
                                                highBed[i - k][j + k].dir = slugSpawnDir;
                                                highBed[i - k][j + k].hasCompletedTurn = true;
                                                highBed[i][j].hasCompletedTurn = true;
                                            }
                                            break;
                                        case 6:
                                            if (directions[slugSpawnLocation].type == EMPTY) {
                                                highBed[i - k][j] = newSlug;
                                                highBed[i - k][j].dir = slugSpawnDir;
                                                highBed[i - k][j].hasCompletedTurn = true;
                                                highBed[i][j].hasCompletedTurn = true;
                                            }
                                            break;
                                        case 7:
                                            if (directions[slugSpawnLocation].type == EMPTY) {
                                                highBed[i - k][j - k] = newSlug;
                                                highBed[i - k][j - k].dir = slugSpawnDir;
                                                highBed[i - k][j - k].hasCompletedTurn = true;
                                                highBed[i][j].hasCompletedTurn = true;
                                            }
                                            break;
                                        default:
                                            break;
                                    }
                                }
                            }
                        }
                        if (highBed[i][j].hasCompletedTurn == false) { //This handles movement if no food
                            int moveDir = highBed[i][j].dir;
                            switch (moveDir) {
                                case 1:
                                    if (highBed[i][j - 1].type == EMPTY) {
                                        highBed[i][j - 1].hasCompletedTurn = true;
                                        highBed[i][j - 1] = highBed[i][j];
                                        highBed[i][j] = emptySpace;
                                        break;
                                    }
                                    highBed[i][j].dir = random_range(NORTH, WEST);
                                    break;
                                case 2:
                                    if (highBed[i + 1][j - 1].type == EMPTY) {
                                        highBed[i + 1][j - 1].hasCompletedTurn = true;
                                        highBed[i + 1][j - 1] = highBed[i][j];
                                        highBed[i][j] = emptySpace;
                                        break;
                                    }
                                    highBed[i][j].dir = random_range(NORTH, WEST);
                                    break;
                                case 3:
                                    if (highBed[i + 1][j].type == EMPTY) {
                                        highBed[i + 1][j].hasCompletedTurn = true;
                                        highBed[i + 1][j] = highBed[i][j];
                                        highBed[i][j] = emptySpace;
                                        break;
                                    }
                                    highBed[i][j].dir = random_range(NORTH, WEST);
                                    break;
                                case 4:
                                    if (highBed[i + 1][j + 1].type == EMPTY) {
                                        highBed[i + 1][j + 1].hasCompletedTurn = true;
                                        highBed[i + 1][j + 1] = highBed[i][j];
                                        highBed[i][j] = emptySpace;
                                        break;
                                    }
                                    highBed[i][j].dir = random_range(NORTH, WEST);
                                    break;
                                case 5:
                                    if (highBed[i][j + 1].type == EMPTY) {
                                        highBed[i][j + 1].hasCompletedTurn = true;
                                        highBed[i][j + 1] = highBed[i][j];
                                        highBed[i][j] = emptySpace;
                                        break;
                                    }
                                    highBed[i][j].dir = random_range(NORTH, WEST);
                                    break;
                                case 6:
                                    if (highBed[i - 1][j + 1].type == EMPTY) {
                                        highBed[i - 1][j + 1].hasCompletedTurn = true;
                                        highBed[i - 1][j + 1] = highBed[i][j];
                                        highBed[i][j] = emptySpace;
                                        break;
                                    }
                                    highBed[i][j].dir = random_range(NORTH, WEST);
                                    break;
                                case 7:
                                    if (highBed[i - 1][j].type == EMPTY) {
                                        highBed[i - 1][j].hasCompletedTurn = true;
                                        highBed[i - 1][j] = highBed[i][j];
                                        highBed[i][j] = emptySpace;
                                        break;
                                    }
                                    highBed[i][j].dir = random_range(NORTH, WEST);
                                    break;
                                case 8:
                                    if (highBed[i - 1][j - 1].type == EMPTY) {
                                        highBed[i - 1][j - 1].hasCompletedTurn = true;
                                        highBed[i - 1][j - 1] = highBed[i][j];
                                        highBed[i][j] = emptySpace;
                                        break;
                                    }
                                    highBed[i][j].dir = random_range(NORTH, WEST);
                                    break;
                                default:
                                    highBed[i][j].dir = random_range(NORTH, WEST);
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
                                        frogSpawnLocation = random_range(0, 7);
                                        directions[frogSpawnLocation] = newFrog;
                                    }
                                }
                            }
                            //This checks every direction as far as the frog can see, if there's
                            //food the frog will move to that location, removing the slug and reset
                            //the frog's hunger level
                            if (highBed[i][j].hasCompletedTurn == false) {
                                int range = newFrog.f.visionDistance;
                                for (int l = 1; l <= range; l++) {
                                    if (highBed[i][j + l].type == SLUG) {
                                        highBed[i][j + l].f.hunger = 0;
                                        highBed[i][j + l] = highBed[i][j];
                                        highBed[i][j + l] = emptySpace;
                                        break;
                                    }
                                    if (highBed[i][j - l].type == SLUG) {
                                        highBed[i][j - l].f.hunger = 0;
                                        highBed[i][j - l] = highBed[i][j];
                                        highBed[i][j - l] = emptySpace;
                                        break;
                                    }
                                    if (highBed[i + l][j - l].type == SLUG) {
                                        highBed[i + l][j - l].f.hunger = 0;
                                        highBed[i + l][j - l] = highBed[i][j];
                                        highBed[i + l][j - l] = emptySpace;
                                        break;
                                    }
                                    if (highBed[i - l][j + l].type == SLUG) {
                                        highBed[i - l][j + l].f.hunger = 0;
                                        highBed[i - l][j + l] = highBed[i][j];
                                        highBed[i - l][j + l] = emptySpace;
                                        break;
                                    }
                                    if (highBed[i - l][j].type == SLUG) {
                                        highBed[i - l][j].f.hunger = 0;
                                        highBed[i - l][j] = highBed[i][j];
                                        highBed[i - l][j] = emptySpace;
                                        break;
                                    }
                                    if (highBed[i + l][j].type == SLUG) {
                                        highBed[i + l][j].f.hunger = 0;
                                        highBed[i + l][j] = highBed[i][j];
                                        highBed[i + l][j] = emptySpace;
                                        break;
                                    }
                                }
                            }
                            //Moves the frog to a random cell if no food
                            if (highBed[i][j].hasCompletedTurn == false && highBed[i][j].f.hunger > 0) {
                                int range = newFrog.f.visionDistance;
                                for (int l = 1; l <= range; l++) {
                                    if (highBed[i][j + l].type == EMPTY) {
                                        highBed[i][j + l] = highBed[i][j];
                                        highBed[i][j + l] = emptySpace;
                                        break;
                                    }
                                    if (highBed[i][j - l].type == EMPTY) {
                                        highBed[i][j - l] = highBed[i][j];
                                        highBed[i][j - l] = emptySpace;
                                        break;
                                    }
                                    if (highBed[i + l][j - l].type == EMPTY) {
                                        highBed[i + l][j - l] = highBed[i][j];
                                        highBed[i + l][j - l] = emptySpace;
                                        break;
                                    }
                                    if (highBed[i - l][j + l].type == EMPTY) {
                                        highBed[i - l][j + l] = highBed[i][j];
                                        highBed[i - l][j + l] = emptySpace;
                                        break;
                                    }
                                    if (highBed[i - l][j].type == EMPTY) {
                                        highBed[i - l][j] = highBed[i][j];
                                        highBed[i - l][j] = emptySpace;
                                        break;
                                    }
                                    if (highBed[i + l][j].type == EMPTY) {
                                        highBed[i + l][j] = highBed[i][j];
                                        highBed[i + l][j] = emptySpace;
                                        break;
                                    }
                                }
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
}


//Handles input for number of days to run
int runSimulation(int d) {
    for(int i = 0; i < d; i++) {
        /*char prev = 0;

        while(1)
        {
            char c = getchar();

            if(c == '\n' && prev == c)
            {*/
                movesManager();
                updateOrganismMaturity();
                nextTurn();
                //clear_output(); //Used for terminal simulation
                printDisplayType();
/*        printf("Run next round?\n"); //TODO ask for next simulation round
        char input;
        scanf("%s", &input); //load config*/
                /*break;
            }

            prev = c;
        }*/
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
                if (newSlug.s.slugMatureAge <= highBed[i][j].age) {
                    highBed[i][j].isMature = true;
                    strcpy(highBed[i][j].displayType, " S ");
                }
            }
            if (highBed[i][j].type == FROG){
                if (newFrog.f.frogMatureAge <= highBed[i][j].age) {
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
