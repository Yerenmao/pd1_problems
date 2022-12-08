#include <stdio.h>
#include <math.h>
#define PI 3.14

int main(void) {
    int mode; double l, w, h;
    scanf("%d", &mode);
    switch(mode) {
        case 1: scanf("%lf", &l);
            printf("%.2f", l * l * l); break;
        case 2: scanf("%lf %lf %lf", &l, &w, &h);
            printf("%.2f", l * w * h); break;
        case 3: scanf("%lf %lf", &l, &w);
            printf("%.2f", PI * l * l * w); break;
        case 4: scanf("%lf", &l);
            printf("%.2f", sqrt(2) * l * l * l / 12); break;
    }
    return 0;
}
