
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key, value;
    struct Node *prev, *next;
} Node;

typedef struct {
    int capacity, count;
    Node *head, *tail;
    Node **map;
} LRUCache;

Node* newNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->prev = node->next = NULL;
    return node;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->count = 0;
    obj->head = obj->tail = NULL;
    obj->map = (Node**)calloc(10001, sizeof(Node*)); // assuming keys <= 10000
    return obj;
}

void moveToFront(LRUCache* obj, Node* node) {
    if (obj->head == node) return;
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    if (obj->tail == node) obj->tail = node->prev;

    node->prev = NULL;
    node->next = obj->head;
    if (obj->head) obj->head->prev = node;
    obj->head = node;
    if (!obj->tail) obj->tail = node;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node* node = obj->map[key];
    if (!node) return -1;
    moveToFront(obj, node);
    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node* node = obj->map[key];
    if (node) {
        node->value = value;
        moveToFront(obj, node);
    } else {
        node = newNode(key, value);
        obj->map[key] = node;
        if (obj->count < obj->capacity) {
            node->next = obj->head;
            if (obj->head) obj->head->prev = node;
            obj->head = node;
            if (!obj->tail) obj->tail = node;
            obj->count++;
        } else {
            obj->map[obj->tail->key] = NULL;
            if (obj->tail->prev) obj->tail->prev->next = NULL;
            obj->tail = obj->tail->prev;
            node->next = obj->head;
            obj->head->prev = node;
            obj->head = node;
        }
    }
}
