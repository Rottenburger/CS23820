//
// Created by Thomas Roethenbaugh on 30/11/2022.
//
#define DEBUG

#define GARDEN_SIZE 12
#define BUFFER_SIZE 1024

#include <stdbool.h>

//int day; //Timer for each round of the simulation

typedef enum {NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST, NORTH_WEST, STATIONARY} direction;
typedef enum {LETTUCE, SLUG, FROG, EMPTY, WALL} type;

struct lettuce {
    double growProb;
};

struct slug {
    double slugReproduceProb;
    int slugLifespan;
    int slugMatureAge;
};

struct frog {
    double frogReproduceProb;
    int frogLifespan;
    int frogMatureAge;
    int visionDistance;
    int hunger;
};

/**
 * This structure forms the basis for all the organisms in
 * the simulation. It contains all the paramenters for each
 * type of creature which could get confusing if more creatures
 * or paramenters are added. However, given the minimal number
 * it should be sufficent for now.
 * Varibles include its location, direction, type, display type
 * (used for printing) etc.
 */
struct organism {
    int row;
    int column;
    int age;
    bool isMature;
    bool hasCompletedTurn;
    type type;
    direction dir;
    char displayType[3];

    struct lettuce l;
    struct slug s;
    struct frog f;
};

//Output functions
void printHighBed();
void printDisplayType();

//Config functions
void openConfig();
void readConfigData();

//Init functions
void fillHighBed();
void createWalls();

//Simulation functions
int runSimulation(int i);
void movesManager();
void nextTurn();
void updateOrganismMaturity();
void clear_output();
