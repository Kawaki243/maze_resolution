#ifndef MAZE_H
#define MAZE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    bool left;
    bool right;
    bool up;
    bool down;
    bool start;
    bool end;
    // Create relationship of cells in the shortest path from start cell to the end cell
    // path[0] : relationship to the left cell in the shortest path of cells
    // path[1] : relationship to the right cell in the shortest path of cells
    // path[2] : relationship to the up cell in the shortest path of cells
    // path[3] : relationship to the down cell in the shortest path of cells
    // at the beginning , path[i] = 0
    int path[4]; 
} Cell;

typedef struct maze {
    int width;
    int height;
    Cell **grid;
} Maze;

// Prototypes of functions
Maze* init_maze(int width, int height);
void free_maze(Maze* maze);
void print_maze(Maze* maze);

// GPT : Path Finding
bool has_path(Maze* maze);

#endif
