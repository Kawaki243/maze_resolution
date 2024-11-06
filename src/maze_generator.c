#include "../include/maze.h"
#include "../include/maze_generator.h"

// Function to place a horizontal wall with an opening (door)
void divide_horizontal(Maze* maze, int y, int x_start, int x_end) {
    // Random position of the door in the wall
    int door_x = x_start + rand() % (x_end - x_start + 1);
    
    for (int x = x_start; x <= x_end; x++) {
        if (x != door_x) {
            maze->grid[y][x].down = true;
            maze->grid[y + 1][x].up = true;
        }
    }
}

// Function to place a vertical wall with an opening (door)
void divide_vertical(Maze* maze, int x, int y_start, int y_end) {
    // (Rand is init in main)
    int door_y = y_start + rand() % (y_end - y_start + 1);
    
    for (int y = y_start; y <= y_end; y++) {
        if (y != door_y) {
            maze->grid[y][x].right = true;
            maze->grid[y][x + 1].left = true;
        }
    }
}

// Function to divide the maze recursively
void divide(Maze* maze, int x_start, int x_end, int y_start, int y_end) {
    // If zone is too small, stop !!!!
    if (x_end - x_start < 1 || y_end - y_start < 1) {
        return;
    }

    // Décider si on divise horizontalement ou verticalement en fonction de la plus longue dimension
    // Si la hauteur est plus grande que la largeur, diviser horizontalement
    // Sinon, diviser verticalement
    // Au lieu que ce soit random cela permet de faire des labyrinthes plus bleau ^^
    bool divide_horizontally = (y_end - y_start > x_end - x_start);

    if (divide_horizontally) {
        // Dividing horizontally randomly
        int wall_y = y_start + rand() % (y_end - y_start);  // Choose a position for the dividing wall (random not divide in 2) !!!!!!!!
        
        // Divide in 2 every time
        // int wall_y = y_start + (y_end - y_start) / 2;

        divide_horizontal(maze, wall_y, x_start, x_end);

        // Recursive call for the two subspaces
        divide(maze, x_start, x_end, y_start, wall_y);
        divide(maze, x_start, x_end, wall_y + 1, y_end);

    } else {
        // Dividing vertically
        int wall_x = x_start + rand() % (x_end - x_start);
        divide_vertical(maze, wall_x, y_start, y_end);

        // Recursive call for the two subspaces
        divide(maze, x_start, wall_x, y_start, y_end);
        divide(maze, wall_x + 1, x_end, y_start, y_end);
    }
}

// Main function to generate the maze
void generate_maze(Maze* maze) {
    // Place exit at bottom right
    int exit_x = maze->width - 1;
    int exit_y = maze->height - 1;
    maze->grid[exit_y][exit_x].end = true;

    // Place entry in random position but not in exit
    int entry_x, entry_y;
    do {
        entry_x = rand() % maze->width;
        entry_y = rand() % maze->height;
    } while (entry_x == exit_x && entry_y == exit_y);
    maze->grid[entry_y][entry_x].start = true;
    
    // Call recursive function to divide the maze
    divide(maze, 0, maze->width - 1, 0, maze->height - 1);
}