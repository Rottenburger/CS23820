CS23820 Assignment 2022 – 2023
Garden Paradise
Thomas Roethenbaugh

Files:
main.c - Handles the menu and controls which functions are called throughout the program
garden.h - Container for global structs and enums, also allows the main.c to access each function
garden_initialise.c - Declares each type of organism struct and creates an empty 2D array of organism structs
garden_output.c - Handles all the printing functions independent of the simulation
garden_readconfig.c - Is supposed to read the config text files (see known bugs)
garden_simulation.c - Handles the simulation of the 2D grid, most of this functionally is contained in the movesManager

CMakeLists.txt - Used to compile program

config1.txt
config2.txt
config3.txt

Important functions:


Known bugs:
-Frog never moves
-Read config not working