#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertFirst(struct Node** head, int value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

void insertAfter(struct Node* head, int key, int value) {

    struct Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void deleteNode(struct Node** head, int key) {

    struct Node* temp = *head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void printForward(struct Node* head) {

    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printBackward(struct Node* head) {

    struct Node* temp = head;

    if (temp == NULL)
        return;

    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {

    struct Node* head = NULL;

    insertFirst(&head, 10);
    insertFirst(&head, 20);
    insertFirst(&head, 30);

    printForward(head);

    insertAfter(head, 20, 25);
    printForward(head);

    deleteNode(&head, 10);
    printForward(head);

    printBackward(head);

    return 0;
}