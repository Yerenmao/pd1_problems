#include <stdio.h>
#include <math.h>
#define sqrt3 1.7320508f

int main(void) {
    int a;
    scanf("%d", &a);
    printf("%.3f", sqrt3 / 4 * pow(a,2));
    return 0;
}
