#include <stdio.h>

int main(void) {
    int n, max, min;
    scanf("%d", &n);
    max = min = n;
    while(1) {
        scanf("%d", &n);
        if(n == -1) break;
        if(n > max) max = n;
        if(n < min) min = n;
    }
    printf("%d", max - min);
    return 0;
}
