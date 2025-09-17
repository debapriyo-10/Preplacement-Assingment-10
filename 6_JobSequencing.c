
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, deadline, profit;
} Job;

int cmp(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

void jobScheduling(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), cmp);
    int result[n], slot[n];
    for (int i = 0; i < n; i++) slot[i] = 0;
    int count = 0, totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                slot[j] = 1;
                count++;
                break;
            }
        }
    }
    printf("Jobs done: %d, Total Profit: %d\n", count, totalProfit);
}
