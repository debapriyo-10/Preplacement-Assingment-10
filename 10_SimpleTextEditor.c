
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

char text[MAX] = "";
char history[100][MAX];
int histTop = -1;

void append(char* s) {
    strcpy(history[++histTop], text);
    strcat(text, s);
}

void delete(int k) {
    strcpy(history[++histTop], text);
    text[strlen(text) - k] = '\0';
}

void print(int k) {
    printf("%c\n", text[k-1]);
}

void undo() {
    strcpy(text, history[histTop--]);
}
