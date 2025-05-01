#include <stdio.h>
#include <stdbool.h>

#define N 9
void printGrid(int grid[N][N]) {
	int row,col;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}
bool isValid(int grid[N][N], int row, int col, int num) {
	int x;
    for (x = 0; x < N; x++) {
        if (grid[row][x] == num)
            return false;
    }
    for (x = 0; x < N; x++) {
        if (grid[x][col] == num)
            return false;
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    int i,j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }

    return true;
}
bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool emptyFound = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                emptyFound = true;
                break;
            }
        }
        if (emptyFound)
            break;
    }
    if (!emptyFound)
        return true;
    int num;
    for (num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }

    return false; 
}
int main() {
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid)) {
        printf("Solved Sudoku Puzzle:\n");
        printGrid(grid);
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}

