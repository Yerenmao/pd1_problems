/*
 * [Loader Code]
#include <stdio.h>

typedef unsigned long long uint64_t;

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1);

int main()
{
    unsigned k;
    scanf("%u", &k);

    uint64_t f2k, f2k1;
    fib_fast_doubling(k / 2, &f2k, &f2k1);

    printf("%llu", (k & 0x1) ? f2k1 : f2k);

    return 0;
}
*/

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1) {
    if(k == 0) {
        *f2k1 = 1; return;
    }
    if(k == 1) {
        *f2k = 1; *f2k1 = 2; return;
    }
    fib_fast_doubling(k/2, f2k, f2k1);
    if(k%2) {
        uint64_t temp = *f2k1;
        *f2k1 = *f2k + *f2k1;
        *f2k = temp;
    }
    uint64_t of2k = *f2k, of2k1 = *f2k1;
    *f2k = of2k * ( 2 * of2k1 - of2k);
    *f2k1 = of2k * of2k + of2k1 * of2k1;
}
