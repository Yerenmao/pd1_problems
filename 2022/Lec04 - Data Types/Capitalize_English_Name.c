#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n); getchar();
    int firstLetter = 1; char ch;
    for(int s = 0; s != n; ) {
        ch = getchar();
        if(ch == ' ' || ch == ',' || ch == '.' || ch == ';') {
            firstLetter = 1;
            putchar(ch == ' ' ? ' ' : '\n');
            if(ch != ' ')
                s++;
        } else {
            if(firstLetter) {
                putchar('a' <= ch && ch <= 'z' ? ch - ('a' - 'A') : ch);
                firstLetter = 0;
            } else
                putchar('A' <= ch && ch <= 'Z' ? ch + ('a' - 'A') : ch);
        }
    }
    return 0;
}
