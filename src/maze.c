#include "../include/maze.h"

// Init Maze with width and height
Maze* init_maze(int width, int height) {
    Maze *maze = (Maze*)malloc(sizeof(Maze));
    if (maze == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    maze->width = width;
    maze->height = height;
    
    // Allocation memory for grid
    maze->grid = (Cell**)malloc(height * sizeof(Cell*));
    if (maze->grid == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < height; i++) {
        maze->grid[i] = (Cell*)malloc(width * sizeof(Cell));
        if (maze->grid[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(1);
        }
        for (int j = 0; j < width; j++) {
            maze->grid[i][j] = (Cell){false, false, false, false, false, false}; // -> all args to false (no walls)
        }
    }
    return maze;
}

// Free Maze
void free_maze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->grid[i]); // Free each row
    }
    free(maze->grid); // Free pointer to rows (grid)
    free(maze); // Free maze struct
}


void print_maze(Maze* maze) {
    // Top wall
    for (int j = 0; j < maze->width; j++) {
        printf("+---");  // top wall of each cell
    }
    printf("+\n");  // Dernier coin top right

    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            // left wall of each cell
            if (maze->grid[i][j].left || j == 0) {
                printf("|");
            } else {
                printf(" ");
            }

            // Cell content
            if (maze->grid[i][j].start) {
                printf(" S "); // Start cell
            } else if (maze->grid[i][j].end) {
                printf(" E "); // End cell
            } else {
                printf("   ");  // Cellule vide
            }
        }
        printf("|\n");  // Last right wall

        // Bottom wall of each cell
        for (int j = 0; j < maze->width; j++) {
            if (maze->grid[i][j].down || i == maze->height - 1) {
                printf("+---");
            } else {
                printf("+   ");
            }
        }
        printf("+\n");  // Last corner of each row
    }
}
