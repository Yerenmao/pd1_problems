#include <stdio.h>

int main(void) {
    char *attacker, *hit;
    int d1, d2, d3, d4, d5, d6;
    scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);
    if(d1 + d2 + d3 <= 10) {
        attacker = "Player";
        if(d4 == d5 && d5 == d6)
            hit = "Critical Hit";
        else if(d4 + d5 >= d6)
            hit = "Normal Hit";
        else
            hit = "Miss";
    } else {
        attacker = "Dragon";
        if(d4 == d5 || d5 == d6 || d6 == d4)
            hit = "Miss";
        else if(d4 + d5 != d6)
            hit = "Normal Hit";
        else
            hit = "Critical Hit";
    }
    printf("%s attacks: %s", attacker, hit);
    return 0;
}
