
#include <stdio.h>

int maxHist(int row[], int n) {
    int stack[n], top = -1;
    int max_area = 0, area = 0, i = 0;
    while (i < n) {
        if (top == -1 || row[stack[top]] <= row[i]) stack[++top] = i++;
        else {
            int tp = stack[top--];
            area = row[tp] * (top == -1 ? i : i - stack[top] - 1);
            if (area > max_area) max_area = area;
        }
    }
    while (top != -1) {
        int tp = stack[top--];
        area = row[tp] * (top == -1 ? i : i - stack[top] - 1);
        if (area > max_area) max_area = area;
    }
    return max_area;
}

int maxRectangle(int M[4][4], int R, int C) {
    int result = maxHist(M[0], C);
    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++)
            if (M[i][j]) M[i][j] += M[i - 1][j];
        int cur = maxHist(M[i], C);
        if (cur > result) result = cur;
    }
    return result;
}
