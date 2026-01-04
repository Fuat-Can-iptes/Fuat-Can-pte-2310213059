#include <stdio.h>

void hanoi(int n, char from, char to, char help) {
    
    if (n == 1) {
        printf("Disk 1: %c -> %c\n", from, to);
        return;
    }

    hanoi(n - 1, from, help, to);

    printf("Disk %d: %c -> %c\n", n, from, to);

    hanoi(n - 1, help, to, from);
}

int main() {

    int diskSayisi;

    printf("Disk sayisini giriniz: ");
    scanf("%d", &diskSayisi);

    hanoi(diskSayisi, 'A', 'C', 'B');

    return 0;
}