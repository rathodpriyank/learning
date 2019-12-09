#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include "common.h"

void printList (node_t *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

node_t *allocate(int data) {
    node_t *node = (node_t*) malloc (sizeof(node_t));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

void prependNode (node_t **head, int data) {
    if (head != NULL) {
        node_t *newnode = allocate(data);
        newnode->next = (*head);
        (*head) = newnode;
    }
}

void appendNode(node_t **head, int data) {
    if (head != NULL) {
        node_t *node = (*head);
        while (node->next != NULL)
            node = node->next;
        node->next = allocate(data);
    }
}

int main (int argc, char *argv[]) {
    int i = 0;
    node_t *head = NULL;
    int arr[] = { 5, 2, 10, 21, 40 };
    int len  = sizeof(arr) / sizeof (int);
    int sarr[] = { 54, 79, 22, 90, };
    int len1 = sizeof(sarr) / sizeof (int);

    for(i = 0; i < len; i++)
        prependNode(&head, arr[i]);

    for(i = 0; i < len1; i++)
        appendNode(&head, sarr[i]);

    printList(head);
    return 0;
}