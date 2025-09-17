
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Element;

int cmp(const void* a, const void* b) {
    return ((Element*)b)->freq - ((Element*)a)->freq;
}

void topKFrequent(int arr[], int n, int k) {
    Element freq[1000] = {0};
    int count[1000] = {0};
    int idx = 0;
    for (int i = 0; i < n; i++) count[arr[i]]++;
    for (int i = 0; i < 1000; i++) {
        if (count[i]) {
            freq[idx].num = i;
            freq[idx].freq = count[i];
            idx++;
        }
    }
    qsort(freq, idx, sizeof(Element), cmp);
    for (int i = 0; i < k && i < idx; i++) printf("%d ", freq[i].num);
}
