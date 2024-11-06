#include <time.h> // For measuring time
#include "../include/maze.h"
#include "../include/maze_generator.h"
#include "../include/path_finding.h"

void test_maze_path(int width, int height) {
    printf("Testing maze of size %dx%d...\n", width, height);
    Maze* maze = init_maze(width, height);
    generate_maze(maze);

    int path_length = pathLength(maze);
    
    if (path_length < 1) {
        fprintf(stderr, "Error: No path found in maze of size %dx%d\n", width, height);
        free_maze(maze);
        exit(1);
    }
    
    free_maze(maze);
    printf("Test passed for maze of size %dx%d with path length %d.\n", width, height, path_length);
}

int main() {
    // Path finding tests - Kylian

    // List of maze sizes to test
    int sizes[][2] = {
        {5, 5},
        {10, 10},
        {20, 20},
        {30, 30},
        {40, 40},
        {50, 50},
        {60, 60},
        {70, 70},
        {80, 80},
        {90, 90},
        {100, 100},
        {200, 200},
        {300, 300},
        {1000,1000},
        {5000,5000},
        {10000,10000}
    };
    int num_tests = sizeof(sizes) / sizeof(sizes[0]);
    
    // Start timer for overall tests
    clock_t overall_start = clock();

    for (int i = 0; i < num_tests; i++) {
        // Start timer for individual test
        clock_t start = clock();

        test_maze_path(sizes[i][0], sizes[i][1]);

        // End timer for individual test
        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Test for maze %dx%d completed in %.2f seconds.\n", sizes[i][0], sizes[i][1], time_taken);
    }

    // End timer for overall tests
    clock_t overall_end = clock();
    double total_time_taken = (double)(overall_end - overall_start) / CLOCKS_PER_SEC;
    printf("All tests completed in %.2f seconds.\n", total_time_taken);

    // End of tests
    printf("All tests OK.\n");
    return 0;
}