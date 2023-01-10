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
movesManager - Loops through the 2D grid every turn to simulate the highbed
printDisplayType - Used to display the highbed and called every round of the simulation
runSimulation - Manages each round of the simulation
fillHighBed - Fills the high bed with empty cells and organisms like lettuce, slugs and frogs

Known bugs:
-Frog never moves despite program saying it does
-Read config not working
-Slugs sometimes move incorrectly