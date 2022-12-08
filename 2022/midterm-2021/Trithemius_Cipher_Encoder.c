#include <stdio.h>

char encode(char c, int n) {
    if('a' <= c && c <= 'z')
        return c + n > 'z' ? c + n - 26 : c + n;
    if('A' <= c && c <= 'Z')
        return c + n > 'Z' ? c + n - 26 : c + n;
    return '\0';
}

int main(void) {
    int k; scanf("%d", &k); getchar();
    k = k % 26; k = (k + 26) % 26;
    char ad = getchar(); getchar();
    char ch, en;
    while(1) {
        ch = getchar();
        if(ch == '\n') break;
        if(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
            en = encode(ch, k);
            putchar(en);
            switch(ad) {
                case 'a': k = (k + 1) % 26; break;
                case 'd': k = (k + 25) % 26; break;
            }
            continue;
        }
        putchar(ch);
    }
    return 0;
}
