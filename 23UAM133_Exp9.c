#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int arr[], int n, int target) {
    bool dp[n + 1][target + 1];
    int i,j;

    for ( i = 0; i <= n; i++)
        dp[i][0] = true;

    for ( j = 1; j <= target; j++)
        dp[0][j] = false;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= target; j++) {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j]; 
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]; 
        }
    }

    return dp[n][target];
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int target = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSubsetSum(arr, n, target))
        printf("There exists a subset with sum %d.\n", target);
    else
        printf("No subset with sum %d exists.\n", target);

    return 0;
}

