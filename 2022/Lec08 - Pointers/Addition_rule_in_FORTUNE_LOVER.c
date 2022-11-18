#include <stdio.h>

void print_binary(void *n) {
    for(int i = 31; i >= 0; i--) {
        printf("%d", (((*(unsigned int*)n)) >> i) & 1);
        if(!(i % 8) && i) putchar(' ');
        if(!i) putchar('\n');
    }
}

int main(void) {
    float a, b;
    scanf("%f %f", &a, &b);
    int ans = *(int*)&a + *(int*)&b;
    printf("   "); print_binary(&a);
    printf("+) "); print_binary(&b);
    printf("---------------------------------------\n");
    printf("   "); print_binary(&ans);
    printf("%d + %d = %d", (int)a, (int)b, ans);
}
