#include <stdio.h>

int abs(int n) {
    return n > 0 ? n : -n;
}

int main(void) {
    int playerHp = 100, dragonHp = 100;
    int d1, d2, d3, d4, d5, d6;
    while(1) {
        scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);
        if((d1+d2+d3) % 2) {
            // player attacks
            if(d4 < d5 && d5 < d6) 
                dragonHp -= 25;
            else if((d4%2 == d5%2) || (d5%2 == d6%2)) 
                dragonHp -= 5;
        } else {
            // dragon attacks
            if(abs(d5-d4) > d6)
                playerHp -= 15;
            else if(d4+d5 != d6)
                playerHp -= 5;
        }
        if(playerHp <= 0) {
            printf("Dragon wins"); break;
        }
        if(dragonHp <= 0) {
            printf("Player wins"); break;
        }
    }
    return 0;
}
