//
// Created by Thomas Roethenbaugh on 06/01/2023.
//
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "garden.h"
#include <time.h>
extern struct organism highBed[GARDEN_SIZE][GARDEN_SIZE];

void movesManager(){
    //float growChance = randomBetween0and1;

    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            switch (highBed[i][j].type) {
                case 1:
                    //growChance = random0to1();
                    if(highBed[i][j].growProb < random0to1()){
                        highBed[i][j+1];
                    }
                    break;
                case 2:
                    // code block
                    break;
                default:
                    // move on to the next cell
                    break;
            } 
        }

    }
}

void rounds(){

}

void lettuceMove(){

}

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
