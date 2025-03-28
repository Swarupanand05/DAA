#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    int resources;
    int profit;
} Job;

int compare(const void *a, const void *b) {
    double ratioA = ((Job *)a)->profit / (double)((Job *)a)->resources;
    double ratioB = ((Job *)b)->profit / (double)((Job *)b)->resources;
    
    if (ratioA > ratioB) return -1;  
    if (ratioA < ratioB) return 1;
    return 0;
}

void allocateResources(Job jobs[], int n, int totalResources) {
   
    qsort(jobs, n, sizeof(Job), compare);
    
    printf("Allocated Jobs: ");
    int usedResources = 0, totalProfit = 0;
	int i;
    for (i = 0; i < n; i++) {
        if (usedResources + jobs[i].resources <= totalResources) {
          
            printf("%s ", jobs[i].name);
            usedResources += jobs[i].resources;
            totalProfit += jobs[i].profit;
        }
    }
    
    printf("\nTotal Profit: %d\n", totalProfit);
}
int main() {

    Job jobs[] = {
        {"Job1", 2, 50},
        {"Job2", 3, 60},
        {"Job3", 4, 70},
        {"Job4", 5, 100}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]); 
    int totalResources = 10;  
    allocateResources(jobs, n, totalResources);
    return 0;
}

