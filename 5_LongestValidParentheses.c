
#include <stdio.h>
#include <string.h>

int longestValidParentheses(char* s) {
    int n = strlen(s), stack[n], top = -1, maxlen = 0;
    stack[++top] = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') stack[++top] = i;
        else {
            top--;
            if (top == -1) stack[++top] = i;
            else {
                int len = i - stack[top];
                if (len > maxlen) maxlen = len;
            }
        }
    }
    return maxlen;
}
