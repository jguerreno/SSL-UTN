#ifndef NUESTRA_LIB_
#define NUESTRA_LIB_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data);
void push(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void append(struct Node** head_ref, int new_data);
void printList(struct Node *node);
void deleteNode(struct Node** head_ref, int key);
void deleteList(struct Node** head_ref);
void deleteNodeAt(struct Node **head_ref, int position);
int getListLength(struct Node* head);
int search(struct Node* head, int x);
#endif  // NUESTRA_LIB_