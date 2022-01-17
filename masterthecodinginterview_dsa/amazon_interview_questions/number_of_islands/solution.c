#include<string.h>
#include<stdio.h>

void traceIsland(char** grid, int rowSize, int colSize, int row, int col, char (*visited)[colSize]){
    //DFS
    int directions[][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
    int ndir = sizeof(directions)/sizeof(directions[0]);
    int r, c;
    
    visited[row][col] = 1;
    
    for(int i=0; i<ndir; i++){
        r = row + directions[i][0];
        c = col + directions[i][1];
        
        if(r<0 || r>=rowSize || c<0 || c>=colSize) continue;
        if(visited[r][c] == 1) continue;
        if(grid[r][c] == '1'){
            traceIsland(grid, rowSize, colSize, r, c, visited);
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int rowSize = gridSize;
    int colSize = *gridColSize;
    
    if(rowSize<1) return 0;
    if(colSize<1) return 0;
    
    int islandCount;
    char visited[rowSize][colSize];
    
    memset(visited, 0, sizeof(visited));
    islandCount = 0;
    for(int row=0; row<rowSize; row++){
        for(int col=0; col<colSize; col++){
            if(visited[row][col] == 1) continue;
            
            if(grid[row][col] == '1'){
                islandCount++;
                traceIsland(grid, rowSize, colSize, row, col, visited);
            }
        }
    }
    return islandCount;
}

int main(void){
    char *grid[5] = {
        "11110",
        "11010",
        "11000",
        "00000"
    };
    int gridSize = 4;
    int gridColSize = 5;

    int result = numIslands(grid, gridSize, &gridColSize);
    printf("Expected:%d  Result:%d\n", 1, result);

    return 0;
}
