#include <stdio.h>

int main(void) {
    char ch; int command = 0;
    Strength s = INIT_STRENGTH;
    Obedience o = INIT_OBEDIENCE;
    while((ch = getchar()) != '\n') {
        switch(ch) {
            case 'e': 
                s += STRENGTH_EAT; 
                o -= OBEDIENCE_EAT; 
                break;
            case 't':
                o += OBEDIENCE_TRAIN;
                s -= STRENGTH_TRAIN;
                break;
        }
        if(o >= LEARN_OBEDIENCE && s <= LEARN_STRENGTH) {
            command++; o = INIT_OBEDIENCE;
        }
        if(command >= 5) break;
    }
    printf("%s", command >= 5 ? "Yes" : "No");
    return 0;
}
