#include <stdio.h>
#define MOD_NUMBER 0x7CE66C50E2840000LLU

typedef unsigned long long ll;

ll number[3] = {
    0x38E38E38E38E3800LLU, 
    0x2AAAAAAAAAAAAAAALLU, 
    0x1C71C71C71C71C71LLU
};

int main(void) {
    int d[3]; ll ans = 0;
    scanf("%d %d %d", &d[0], &d[1], &d[2]);
    for(int i = 0; i < 3; i++) {
        ans += (d[i] * (number[i] % MOD_NUMBER))% MOD_NUMBER;
        ans = ans % MOD_NUMBER;
    }
    printf("%llu", ans);
    return 0;
}
