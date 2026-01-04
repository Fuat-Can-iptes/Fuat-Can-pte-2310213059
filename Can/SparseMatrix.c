#include <stdio.h>

#define ROW 3
#define COL 4
#define NONZERO 6

int main() {

    int mat[ROW][COL] = {
        {1, 0, 0, 2},
        {0, 0, 3, 0},
        {4, 0, 5, 6}
    };

    int value[NONZERO];
    int column[NONZERO];
    int row[ROW + 1];

    int index = 0;

    row[0] = 0;

    for (int i = 0; i < ROW; i++) {

        for (int j = 0; j < COL; j++) {

            if (mat[i][j] != 0) {
                value[index] = mat[i][j];
                column[index] = j;
                index++;
            }
        }

        row[i + 1] = index;
    }

    printf("Value array: ");
    for (int i = 0; i < NONZERO; i++) {
        printf("%d ", value[i]);
    }

    printf("\nColumn array: ");
    for (int i = 0; i < NONZERO; i++) {
        printf("%d ", column[i]);
    }

    printf("\nRow array: ");
    for (int i = 0; i < ROW + 1; i++) {
        printf("%d ", row[i]);
    }

    return 0;
}