//
// Created by Thomas Roethenbaugh on 06/01/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "garden.h"

/*extern struct organism lettuce = {
        .growProb = 0.8,
        .type = LETTUCE,
        .displayType = " O ",
};*/


void openConfig() {
    FILE *file = fopen("config1.txt", "r");
    if (file == NULL) {
        perror("config file not found");
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

