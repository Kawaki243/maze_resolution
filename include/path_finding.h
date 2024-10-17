#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_HEIGHT 256
#define MAX_WIDTH 256

typedef struct{
    int height;
    int width;
}Pile;

void ajout(int height, int width);
Pile supprimer();
int check(int height,int width, int current_height, int current_width);
int** createVisited(int rows, int cols);
void freeVisited(int** visited, int rows);
void dfs(Maze* maze,int current_height,int current_width);
void afficher_cell(int height,int width);
void create_visited(int height,int width);
void affcher_stack();