#include <stdio.h>

void printSubset(int subset[], int subsetSize) {
	int i;
    printf("[");
    for (i = 0; i < subsetSize; i++) {
        printf("%d", subset[i]);
        if (i != subsetSize - 1)
            printf(", ");
    }
    printf("]\n");
}

void generateSubsets(int arr[], int n, int index, int subset[], int subsetSize) {
    if (index == n) {
        printSubset(subset, subsetSize);
        return;
    }

    subset[subsetSize] = arr[index];
    generateSubsets(arr, n, index + 1, subset, subsetSize + 1);

    generateSubsets(arr, n, index + 1, subset, subsetSize);
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int subset[n]; 
    printf("All possible subsets:\n");
    generateSubsets(arr, n, 0, subset, 0);

    return 0;
}

