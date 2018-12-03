#include <stdio.h>

int main() {
    char buf[10000];
    while (scanf("%s", buf) != EOF) {
        switch (buf[0]) {
            case 'p':
                printf("scissors");
                break;
            case 's':
                printf("rock");
                break;
            case 'r':
                printf("paper");
                break;
        }
        putchar('\n');
    }
    return 0;
}
