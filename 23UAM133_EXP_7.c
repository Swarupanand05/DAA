#include <stdio.h>

void findMinCoins(int coins[], int numCoins, int amount) {
    int coinCount = 0;
    printf("Coins used: ");
    for (int i = 0; i < numCoins; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            coinCount++;
            printf("%d ", coins[i]);
        }
    }
    printf("\nTotal coins required: %d\n", coinCount);
}

int main() {
    int coins[] = {25, 10, 5, 1}; 
    int numCoins = sizeof(coins) / sizeof(coins[0]);
    int amount = 63;

    printf("Greedy approach to find minimum coins for amount %d:\n", amount);
    findMinCoins(coins, numCoins, amount);

    return 0;
}

