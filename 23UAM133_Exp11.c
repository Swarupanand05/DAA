#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 3
#define COLS 4

int rowDir[] = {-1, 1, 0, 0};
int colDir[] = {0, 0, -1, 1};

bool searchWord(char grid[ROWS][COLS], int row, int col, char* word, int index, bool visited[ROWS][COLS]) {
    if (index == strlen(word))
        return true;

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || visited[row][col] || grid[row][col] != word[index])
        return false;

    visited[row][col] = true;
	int d;
    for (d = 0; d < 4; d++) {
        int newRow = row + rowDir[d];
        int newCol = col + colDir[d];
        if (searchWord(grid, newRow, newCol, word, index + 1, visited)) {
            return true;
        }
    }

    visited[row][col] = false;
    return false;
}

bool exist(char grid[ROWS][COLS], char* word) {
    bool visited[ROWS][COLS] = { false };
	int i,j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (searchWord(grid, i, j, word, 0, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char grid[ROWS][COLS] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    char word[] = "ABCCED";

    if (exist(grid, word)) {
        printf("The word '%s' exists in the grid.\n", word);
    } else {
        printf("The word '%s' does NOT exist in the grid.\n", word);
    }

    return 0;
}

