#include <stdio.h>
#define W 0.9
#define U 0.1
#define B -51
#define U_PRIME -0.98
#define B_PRIME 153

int main(void) {
    double x;
    scanf("%lf", &x);
    double h = 0;
    for(int i = 0; i < 5; i++) {
        h = W * x + U * h + B;
        x = U_PRIME * h + B_PRIME;
        printf("%.1f ", x);
    }
    return 0;
}
