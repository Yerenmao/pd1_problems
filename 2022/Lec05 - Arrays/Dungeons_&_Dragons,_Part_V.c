#include <stdio.h>

int main(void) {
    int d[7] = {0}, d1, d2;
    for(int i = 0; i < 75; i++) {
        scanf("%d %d", &d1, &d2);
        if(d2 % 2)
            d[d1] = d[d1] < 9 ? d[d1]+1 : 0;
        else
            d[d1] = d[d1] > 0 ? d[d1]-1 : 9;
    }
    for(int i = 1; i <= 6; i++) 
        printf("%d ", d[i]);
    return 0;
}
