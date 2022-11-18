#include <stdio.h>
#define AMERICANO  110
#define LATTE      150
#define CAPPUCCINO 135
#define MOCHA      145

int price[4] = {AMERICANO, LATTE, CAPPUCCINO, MOCHA};

int main(void) {
    int type, n;
    scanf("%d %d", &type, &n);
    if(1 <= type && type <= 4)
        printf("The total price is %d dollars!", price[type-1] * n);
    else
        printf("Wait, what?");
    return 0;
}
