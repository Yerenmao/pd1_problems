/*
 * [Loader Code]
#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}
*/

void reset_pos(int *pos) {
    for(int i = 1; i <= NUM; i++)
        pos[i] = -1;
}

void check_sudoku(int (*grid_p)[NUM]) {
    // check the unsatisfy point
    int check[NUM][NUM] = {0};
    // remember the idx/position
    int pos[NUM+1];

    int num;
    reset_pos(pos);
    // check row
    for(int i = 0; i < NUM; i++) {
        for(int j = 0; j < NUM; j++) {
            num = grid_p[i][j];
            if(pos[num] < 0)
                pos[num] = j;
            else {
                check[i][j] = 1;
                check[i][pos[num]] = 1;
            }
        }
        reset_pos(pos);
    }
    // check col
    for(int j = 0; j < NUM; j++) {
        for(int i = 0; i < NUM; i++) {
            num = grid_p[i][j];
            if(pos[num] < 0)
                pos[num] = i;
            else {
                check[i][j] = 1;
                check[pos[num]][j] = 1;
            }
        }
        reset_pos(pos);
    }
    // check block
    for(int row = 0; row < NUM; row += 3) {
        for(int col = 0; col < NUM; col += 3) {
            for(int i = row; i < row + 3; i++) {
                for(int j = col; j < col + 3; j++) {
                    num = grid_p[i][j];
                    if(pos[num] < 0)
                        pos[num] = i * NUM + j;
                    else {
                        check[i][j] = 1;
                        check[pos[num]/NUM][pos[num]%NUM] = 1;
                    }
                }
            }
            reset_pos(pos);
        }
    }
    // print check result
    for(int i = 0; i < NUM; i++)
        for(int j = 0; j < NUM; j++)
            if(check[i][j])
                printf("(%d,%d)\n", i, j);
}
