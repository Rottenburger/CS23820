//
// Created by Thomas Roethenbaugh on 30/11/2022.
//
#define DEBUG

#define GARDEN_SIZE 13
#define BUFFER_SIZE 1024

#include <stdbool.h>

/**
 * Direction enum is used by the slugs to handle movement.
 * It is also used by lettuce to determine growth direction.
 */
typedef enum {NORTH, EAST, SOUTH, WEST, STATIONARY} direction;
/**
 * Type enum used to determine the type of each cell on the
 * grid, the simulation uses this to quickly figure out what
 * is contained in neighbouring cells.
 */
typedef enum {LETTUCE, SLUG, FROG, EMPTY, WALL} type;

/**
 * Lettuce struct that only contains starting growth probability
 */
struct lettuce {
    double growProb;
};

/**
 * Slug struct information used in simulation
 */
struct slug {
    double slugReproduceProb;
    int slugLifespan;
    int slugMatureAge;
};

/**
 * Frog struct information used in simulation
 */
struct frog {
    double frogReproduceProb;
    int frogLifespan;
    int frogMatureAge;
    int visionDistance;
    int hunger;
};

/**
 * This structure forms the basis for all the organisms and cells in
 * the simulation. It contains all the parameters for each
 * type of creature which could get confusing if more creatures
 * or parameters are added. However, given the minimal number
 * it should be sufficient for now.
 * Varibles include its location, direction, type, display type
 * (used for printing) etc.
 * It also contains structs of each type of cell as parameters,
 * this allows the 2D grid to contain any type of cell without
 * the need to track each one.
 */
struct cell {
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

extern bool movesMode;

//Output functions
void printHighBed();
void printDisplayType();
void printAge();

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
void checkIfEnterIsPressed();
