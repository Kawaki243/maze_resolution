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
