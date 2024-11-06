#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_HEIGHT 512
#define MAX_WIDTH 512

typedef struct{
    int height;
    int width;
}Pile;

void ajout(int height, int width);
Pile supprimer();
int check(int height,int width, int current_height, int current_width);
int** createVisited(int rows, int cols);
void freeVisited(int** visited, int rows);
void dfs(Maze* maze);
void afficher_cell(int height,int width);
void create_visited(int height,int width);
void affcher_stack();
void set_relationship(Maze* maze);
void afficher_path(Maze* maze);
void print_maze_after_dfs(Maze* maze);
int pathLength(Maze* maze);
void afficher_maze_with_paths(Maze* maze);