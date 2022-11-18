#include <stdio.h>

int main(void) {
    long n; int a = 0, b = 0;
    scanf("%ld", &n);
    for(int i = 1; i <= 12; i++) {
        if(i%2)
            a += n % 10;
        else
            b += n % 10;
        n /= 10;
    }
    printf("%d", 9 - (a * 3 + b - 1) % 10);
    return 0;
}
