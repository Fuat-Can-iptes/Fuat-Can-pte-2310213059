#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertFirst(struct Node** head, int value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;
    *head = newNode;
}

void insertAfter(struct Node* head, int key, int value) {

    if (head == NULL)
        return;

    struct Node* temp = head;

    do {
        if (temp->data == key) {

            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void deleteNode(struct Node** head, int key) {

    if (*head == NULL)
        return;

    struct Node* curr = *head;
    struct Node* prev = NULL;

    do {
        if (curr->data == key) {

            if (curr == *head) {

                struct Node* temp = *head;
                while (temp->next != *head) {
                    temp = temp->next;
                }

                if (curr->next == *head) {
                    *head = NULL;
                } else {
                    temp->next = curr->next;
                    *head = curr->next;
                }
            } else {
                prev->next = curr->next;
            }

            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;

    } while (curr != *head);
}

void printList(struct Node* head) {

    if (head == NULL)
        return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {

    struct Node* head = NULL;

    insertFirst(&head, 10);
    insertFirst(&head, 20);
    insertFirst(&head, 30);

    printList(head);

    insertAfter(head, 20, 25);
    printList(head);

    deleteNode(&head, 10);
    printList(head);

    deleteNode(&head, 30);
    printList(head);

    return 0;
}