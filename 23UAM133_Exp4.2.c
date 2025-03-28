#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
    float ratio;
};

int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    if (item2->ratio > item1->ratio) return 1;
    else if (item2->ratio < item1->ratio) return -1;
    else return 0;
}

float fractional_knapsack(int weights[], int values[], int W, int n) {
    struct Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].value = values[i];
        items[i].weight = weights[i];
        items[i].ratio = (float)values[i] / weights[i];
    }

    
    qsort(items, n, sizeof(struct Item), compare);

    float total_value = 0.0;
    for (int i = 0; i < n; i++) {
        if (W == 0)
            break;
        if (items[i].weight <= W) {
            W -= items[i].weight;
            total_value += items[i].value;
        } else {
            total_value += items[i].value * ((float)W / items[i].weight);
            break;
        }
    }

    return total_value;
}

int main() {
    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};
    int W = 50;
    int n = sizeof(weights) / sizeof(weights[0]);

    float max_value = fractional_knapsack(weights, values, W, n);
    printf("Maximum value in fractional knapsack = %.2f\n", max_value);

    return 0;
}

