#include <stdio.h>

int main(void) {
    double R, ans = 1; int N;
    scanf("%lf %d", &R, &N);
    while(N--) ans *= R;
    printf("%d", (int)ans);
    return 0;
}
