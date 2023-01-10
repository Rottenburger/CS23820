//
// Created by Thomas Roethenbaugh on 06/01/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "garden.h"

/**
 * All the variables that are contained in the config file
 */
double LETTUCE_GROW_PROB;
double SLUG_REPRODUCE_PROB;
double FROG_REPRODUCE_PROB;
int SLUG_MATURE_AGE;
int FROG_MATURE_AGE;
int SLUG_LIFESPAN;
int FROG_LIFESPAN;
int FROG_HUNGRY;
int FROG_VISION_DISTANCE;

extern char configName;

/**
 * Reads entire config file and prints it to terminal
 */
void openConfig() {
    FILE *file = fopen("config2.txt", "r");
    char line[100];
    char value;

    if (file == NULL) {
        perror("config file not found");
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
/*        value = strtok(NULL, " ");
        LETTUCE_GROW_PROB = strtod(value, NULL);*/


    }
    fclose(file);
}
/**
 * Tries to read config file data into variables that can be used by garden_initialise.c
 */
void readConfigData() {
    float a;
    float b;
    float c;

    FILE *file = fopen("config1.txt", "r");
    fscanf(file, "%*s %f", &a);
    fscanf(file, "%*s %f", &b);
    fscanf(file, "%*s %f", &b);

    fclose(file);

    printf("a: %f\n", a);
    printf("a: %f\n", b);
    printf("a: %f\n", c);
}

