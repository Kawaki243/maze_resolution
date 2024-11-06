// ---------------------------------------------------------
// Implementation of path finding algorithms with ChatGPT
// This is a temporary implementation until the next session
// And is for testing only. Don't pay attention.
// ---------------------------------------------------------

#include "../include/maze.h"
#include "../include/path_finding.h"

// 0 : left, 1 : right, 2 : up, 3 : down
int directionHeight[4] = {0, 0, -1, 1}; // Correspond à LEFT,RIGHT,UP,DOWN
int directionWidth[4] = {-1, 1, 0, 0};// Correspond à LEFT,RIGHT,UP,DOWN
bool** visited;
Pile* stack;
int len = -1; // length courant de la pile

void ajout(int height, int width){ // ajouter la position de la cellule courante à la pile 
	len = len +1;
	stack[len].height = height;
    stack[len].width = width;
}

Pile supprimer(){ // supprimer la dernière cellule à la pile
	len = len-1;
	return stack[len];
}

int check(int height,int width, int current_height, int current_width){
	int a = 0;
	if(current_width >= 0 && current_width < width && current_height >= 0 && current_height < height){
		a = 1;
	}
	return a;
}

void create_visited(int height,int width){
    visited = (bool**)malloc(height * sizeof(bool*));
    for(int i = 0;i<height;i++){
        visited[i] = (bool*)malloc(width * sizeof(bool));
        for(int j = 0;j<width;j++){
            visited[i][j] = 0;
        }
    }
}

// initLigne : ligne de la cellule on commencer
// initColumn : column de la cellule on commencer
void dfs(Maze* maze){
    stack = (Pile*)malloc(maze->width * maze->height * sizeof(Pile));
    if(maze->height == 1 && maze->width == 1){
        fprintf(stderr, "The length of path is 0\n");
        return;
    }
    int start_width;
    int start_height;
    // Gen maze
    for(int i = 0;i<maze->height;i++){
        for(int j = 0;j<maze->width;j++){
            if(maze->grid[i][j].start == true){
                start_height = i;
                start_width = j;
            }
        }
    }
    int current_height = start_height;
    int current_width = start_width;
    create_visited(maze->height,maze->width);
	ajout(current_height,current_width);
    visited[current_height][current_width] = 1;
    //afficher_cell(current_height,current_width);
	while(visited[maze->height-1][maze->width-1] != 1){
		Pile current_cell = stack[len];
		int current_cell_height = current_cell.height;
		int current_cell_width = current_cell.width;
		int directions[4];
		int len_directions = 0;
		// dir = 0 : left
		// dir = 1 : right
		// dir = 2 : up
		// dir = 3 : down
		for (int dir = 0; dir < 4; dir++){
            if(dir == 0){// Check if we can go left or not
                int new_width = current_cell_width+directionWidth[dir];
                int new_height = current_cell_height+directionHeight[dir];
                if(check(maze->height,maze->width,new_height,new_width) == 1 && visited[new_height][new_width]== 0 && maze->grid[current_cell_height][current_cell_width].left == false){
                    directions[len_directions] = dir;
                    len_directions++;
                }
            }
            if(dir == 1){// Check if we can go right or not
                int new_width = current_cell_width+directionWidth[dir];
                int new_height = current_cell_height+directionHeight[dir];
                if(check(maze->height,maze->width,new_height,new_width) == 1 && visited[new_height][new_width]== 0 && maze->grid[current_cell_height][current_cell_width].right == false){
                    directions[len_directions] = dir;
                    len_directions++;
                }
            }
            if(dir == 2){// Check if we can go up or not
                int new_width = current_cell_width+directionWidth[dir];
                int new_height = current_cell_height+directionHeight[dir];
                if(check(maze->height,maze->width,new_height,new_width) == 1 && visited[new_height][new_width]== 0 && maze->grid[current_cell_height][current_cell_width].up == false){
                    directions[len_directions] = dir;
                    len_directions++;
                }
            }
            if(dir == 3){// Check if we can go down or not
                int new_width = current_cell_width+directionWidth[dir];
                int new_height = current_cell_height+directionHeight[dir];
                if(check(maze->height,maze->width,new_height,new_width) == 1 && visited[new_height][new_width]== 0 && maze->grid[current_cell_height][current_cell_width].down == false){
                    directions[len_directions] = dir;
                    len_directions++;
                }
            }
		}
		// Choisissez la direction au hasard
		if(len_directions > 0){
			int direct = directions[rand()%len_directions];
			int nouvelle_width = current_cell_width + directionWidth[direct];
			int nouvelle_height = current_cell_height + directionHeight[direct];
			visited[nouvelle_height][nouvelle_width] = 1;
			ajout(nouvelle_height,nouvelle_width);
			//afficher_cell(nouvelle_height,nouvelle_width);
		}
		else{
			supprimer();
		}
	}
    /*
    
    */
	return;
}

void affcher_stack(){
    if(len < 1){ // Ce n'a pas un chemin du start cellule à end cellule
        fprintf(stderr, "There is no way from starting cell to the ending cell\n");
        return;
    }
    printf("{");
    for(int i = 1;i<len;i++){
        afficher_cell(stack[i].height,stack[i].width);
        printf(", ");
    }
    afficher_cell(stack[len].height,stack[len].width);
    printf("}\n");
    printf("The length of path is %d\n",len);
}
// Afficher la cellule
void afficher_cell(int height,int width){
	printf("( ");
	printf("%d, %d",height,width);
    printf(")");
	return;
}
void set_relationship(Maze* maze){
    for(int i = 0;i<len;i++){
        if(stack[i].width-1 == stack[i+1].width){ // There is a cell in the left in the shortest path of the current cell 
            maze->grid[stack[i].height][stack[i].width].path[0] = 1; // Set the relationship of the current cell
            maze->grid[stack[i+1].height][stack[i+1].width].path[1] = 1; // Set the relationship of the adjacent cell
        }
        else if(stack[i].width+1 == stack[i+1].width){ // There is a cell in the right in the shortest path of the current cell 
            maze->grid[stack[i].height][stack[i].width].path[1] = 1; // Set the relationship of the current cell
            maze->grid[stack[i+1].height][stack[i+1].width].path[0] = 1; // Set the relationship of the adjacent cell
        }
        else if(stack[i].height-1 == stack[i+1].height){ // There is a cell in the up in the shortest path of the current cell 
            maze->grid[stack[i].height][stack[i].width].path[2] = 1; // Set the relationship of the current cell
            maze->grid[stack[i+1].height][stack[i+1].width].path[3] = 1; // Set the relationship of the adjacent cell
        }
        else if(stack[i].height+1 == stack[i+1].height){ // There is a cell in the down in the shortest path of the current cell 
            maze->grid[stack[i].height][stack[i].width].path[3] = 1; // Set the relationship of the current cell
            maze->grid[stack[i+1].height][stack[i+1].width].path[2] = 1; // Set the relationship of the adjacent cell
        }
        else{
            continue;
        }
    }
}

int pathLength(Maze* maze){
    dfs(maze);
    return len;
}

void print_maze_after_dfs(Maze* maze) {
    printf("}\n");
    printf("The length of path is %d\n",len);
    printf("The maze with the shortest path is : \n\n");
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
                if(maze->grid[i][j].path[0] == 1){// left
                    printf("━S ");
                }
                else if(maze->grid[i][j].path[1] == 1){// right
                    printf(" S━");
                }
                else{
                    printf(" S ");
                }
            } else if (maze->grid[i][j].end) {
                if(maze->grid[i][j].path[0] == 1){// left
                    printf("━E ");
                }
                else if(maze->grid[i][j].path[1] == 1){// right
                    printf(" E━");
                }
                else{
                    printf(" E ");
                }
            } else {
                if(maze->grid[i][j].path[0] == 1 && maze->grid[i][j].path[2] == 1){// left up
                    printf("━╹ ");
                }
                else if(maze->grid[i][j].path[0] == 1 && maze->grid[i][j].path[3] == 1){// left down
                    printf("━╻ ");
                }
                else if(maze->grid[i][j].path[1] == 1 && maze->grid[i][j].path[2] == 1){// right up
                    printf(" ╹━");
                }
                else if(maze->grid[i][j].path[1] == 1 && maze->grid[i][j].path[3] == 1){// right down
                    printf(" ╻━");
                }
                else if(maze->grid[i][j].path[0] == 1 && maze->grid[i][j].path[1] == 1){ // left right
                    printf("━ ━");
                }
                else if(maze->grid[i][j].path[2] == 1 && maze->grid[i][j].path[3] == 1){ // up down
                    printf(" ┃ ");
                }
                else{
                    printf("   ");
                }
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

void afficher_maze_with_paths(Maze* maze){
    dfs(maze);
    // To print the path
    //affcher_stack();
    set_relationship(maze);
    print_maze_after_dfs(maze);
    for (int i = 0; i < maze->height; i++) {
        free(visited[i]);
    }
    free(visited);
    free(stack);
}
