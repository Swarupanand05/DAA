#include <stdio.h>
#include <string.h>


int longestPalindromicSubsequence(char *str) {
    int n = strlen(str);
    int dp[n][n];  // DP table
	int i;
    int len;
    for (i = 0; i < n; i++)
        dp[i][i] = 1;

    for (len = 2; len <= n; len++) {
        for (i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (str[i] == str[j]) {
                if (len == 2)
                    dp[i][j] = 2;
                else
                    dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = (dp[i + 1][j] > dp[i][j - 1]) ? dp[i + 1][j] : dp[i][j - 1];
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    char str[] = "BBABCBCAB";
    int result = longestPalindromicSubsequence(str);
    printf("Length of the longest palindromic subsequence: %d\n", result);
    return 0;
}

