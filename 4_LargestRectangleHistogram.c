
#include <stdio.h>

int largestRectangleArea(int* heights, int n) {
    int stack[n], top = -1, max_area = 0, area, i = 0;
    while (i < n) {
        if (top == -1 || heights[stack[top]] <= heights[i]) stack[++top] = i++;
        else {
            int tp = stack[top--];
            area = heights[tp] * (top == -1 ? i : i - stack[top] - 1);
            if (area > max_area) max_area = area;
        }
    }
    while (top != -1) {
        int tp = stack[top--];
        area = heights[tp] * (top == -1 ? i : i - stack[top] - 1);
        if (area > max_area) max_area = area;
    }
    return max_area;
}
