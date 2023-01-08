//
// Created by Thomas Roethenbaugh on 06/01/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "garden.h"

double LETTUCE_GROW_PROB;
double SLUG_REPRODUCE_PROB;
double FROG_REPRODUCE_PROB;
int SLUG_MATURE_AGE;
int FROG_MATURE_AGE;
int SLUG_LIFESPAN;
int FROG_LIFESPAN;
int FROG_HUNGRY;
int FROG_VISION_DISTANCE;

void openConfig() {
    FILE *file = fopen("config1.txt", "r");
    if (file == NULL) {
        perror("config file not found");
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        //printf("%s", buffer);
    }
    fclose(file);

    char *s;
    //sscanf(BUFFER_SIZE, "%d", &SLUG_MATURE_AGE);
    strtol("SLUG_MATURE_AGE", &s, BUFFER_SIZE);
    printf("%d", SLUG_MATURE_AGE);
}

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

