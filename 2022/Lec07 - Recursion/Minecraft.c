#include <stdio.h>
#define MAX_N 20

int table[MAX_N+5][MAX_N+5] = {0};
int amount[MAX_N+5] = {0};

int amount_obj(int obj, int N) {
    if(amount[obj])
        return amount[obj];
    int count = 0;
    for(int i = 1; i <= N; i++)
        if(table[obj][i])
            count += amount_obj(i, N);
    amount[obj] = count;
    return count;
}
        

int main(void) {
    int N, M, k;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &M);
        if(!M) {
            amount[i] = 1;   
        } else {
            for(int j = 0; j < M; j++) {
                scanf("%d", &k);
                table[i][k] = 1;
            }
        }
    }
    int count = 0;
    for(int i = 1; i <= N; i++)
        count += amount_obj(i, N);
    printf("%d", count);
    return 0;
}
