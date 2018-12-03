#include <stdio.h>
char ch;
int words_count=0, word_length=0;
int main() {
    while (~(ch = getchar())) {
        switch (ch) {
            case ',':
            case '.':
            case '!':
            case '?':
            case ' ':
            case ';':
                if (word_length) words_count++, word_length = 0;
                break;
            default:
                if (ch != '\t' && ch != '\n') word_length++;
        }
    }
    if (word_length) words_count++;
    printf("%d", words_count);
    return 0;
}