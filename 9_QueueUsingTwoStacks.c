
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int arr[1000];
    int top;
} Stack;

void push(Stack* s, int x) { s->arr[++s->top] = x; }
int pop(Stack* s) { return s->arr[s->top--]; }
int isEmpty(Stack* s) { return s->top == -1; }
int peek(Stack* s) { return s->arr[s->top]; }

typedef struct {
    Stack s1, s2;
} MyQueue;

MyQueue* createQueue() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->s1.top = q->s2.top = -1;
    return q;
}

void enqueue(MyQueue* q, int x) { push(&q->s1, x); }

void dequeue(MyQueue* q) {
    if (isEmpty(&q->s2)) while (!isEmpty(&q->s1)) push(&q->s2, pop(&q->s1));
    pop(&q->s2);
}

int front(MyQueue* q) {
    if (isEmpty(&q->s2)) while (!isEmpty(&q->s1)) push(&q->s2, pop(&q->s1));
    return peek(&q->s2);
}
