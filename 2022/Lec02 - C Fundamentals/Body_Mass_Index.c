#include <stdio.h>
#include <math.h>

int main(void) {
    int h, w;
    scanf("%d %d", &h, &w);
    printf("%f", w / (float)pow((h/100.0f), 2));
    return 0;
}
