#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int compare(const void *a, const void *b) {
    return ((Interval *)a)->end - ((Interval *)b)->end;
}


void intervalScheduling(Interval intervals[], int n) {
    qsort(intervals, n, sizeof(Interval), compare); 
    printf("Selected intervals: \n");
    
    int last_end_time = -1;
    int i;
    for (i = 0; i < n; i++) {
        if (intervals[i].start >= last_end_time) {
            printf("(%d, %d)", intervals[i].start, intervals[i].end);
            last_end_time = intervals[i].end;
        }
    }
}

int main() {
    Interval intervals[] = {{1, 3}, {2, 5}, {4, 6}, {6, 8}, {5, 7}};
    int n = sizeof(intervals) / sizeof(intervals[0]);
    intervalScheduling(intervals, n);
    return 0;
}

