#include <stdio.h>

int main(void) {
    int n;
    scanf("%x", &n);
    for(int i = 3; i >= 0; i--) {
        printf("%d", (i ? n >> (8 * i) : n) & 0xff);
        if(i) putchar('.');
    }
    return 0;
}
