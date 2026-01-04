#include <stdio.h>

#define MAX 15

int tree[MAX];

void initTree() {
    for (int i = 0; i < MAX; i++) {
        tree[i] = -1;
    }
}

void insert(int value) {

    for (int i = 0; i < MAX; i++) {
        if (tree[i] == -1) {
            tree[i] = value;
            return;
        }
    }
}

void inorder(int index) {

    if (index >= MAX || tree[index] == -1)
        return;

    inorder(2 * index + 1);
    printf("%d ", tree[index]);
    inorder(2 * index + 2);
}

void preorder(int index) {

    if (index >= MAX || tree[index] == -1)
        return;

    printf("%d ", tree[index]);
    preorder(2 * index + 1);
    preorder(2 * index + 2);
}

void postorder(int index) {

    if (index >= MAX || tree[index] == -1)
        return;

    postorder(2 * index + 1);
    postorder(2 * index + 2);
    printf("%d ", tree[index]);
}

int main() {

    initTree();

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);

    printf("Inorder: ");
    inorder(0);

    printf("\nPreorder: ");
    preorder(0);

    printf("\nPostorder: ");
    postorder(0);

    return 0;
}