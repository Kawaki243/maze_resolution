#include "../include/maze.h"
#include "../include/maze_generator.h"
#include "../include/path_finding.h"

int main(int argc, char *argv[]) {
    // Chceck Args NB
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <width> <height>\n", argv[0]);
        return 1;
    }
    
    // Convert to int
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    
    if (width <= 0 || height <= 0) {
        fprintf(stderr, "Width and height must be positive integers.\n");
        return 1;
    }
    
    // init alea gen
    srand(time(NULL));
    
    // Init maze
    Maze* maze = init_maze(width, height);
    
    int start_width;
    int start_height;
    // Gen maze
    generate_maze(maze);
    for(int i = 0;i<height;i++){
        for(int j = 0;j<width;j++){
            if(maze->grid[i][j].start == true){
                start_height = i;
                start_width = j;
            }
        }
    }
    // Print maze with beauti ASCII :)
    print_maze(maze);
    

    dfs(maze,start_height,start_width);


    // Free maze
    free_maze(maze);
    return 0;
}