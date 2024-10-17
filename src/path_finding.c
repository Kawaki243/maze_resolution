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
int visited[MAX_HEIGHT][MAX_WIDTH];
Pile stack[MAX_HEIGHT*MAX_WIDTH]; // créer la pile (Last in first out)
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
    for(int i = 0;i<height;i++){
        for(int j = 0;j<width;j++){
            visited[i][j] = 0;
        }
    }
}

// initLigne : ligne de la cellule on commencer
// initColumn : column de la cellule on commencer
void dfs(Maze* maze,int current_height,int current_width){
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
    affcher_stack();
	return;
}

void affcher_stack(){
    for(int i = 0;i<len+1;i++){
        afficher_cell(stack[i].height,stack[i].width);
    }
}
// Afficher la cellule
void afficher_cell(int height,int width){
	printf("La cellule courante a  : \n");
	printf("Height : %d, Width : %d\n",height,width);
	return;
}