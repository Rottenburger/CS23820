cmake_minimum_required(VERSION 3.23)
project(Project C)

set(CMAKE_C_STANDARD 17)

add_executable(Project main.c garden.h garden_initialise.c garden_output.c garden_readconfig.c garden_simulation.c)
