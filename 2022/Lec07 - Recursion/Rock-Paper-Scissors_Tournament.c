#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX_PLAYER 1024
#define MAX_JUDGE 11

char player[MAX_PLAYER+5];
char judge[MAX_JUDGE+5];

int r_p_s(int, int, int, int);
int getWinner(int, int, int);

int main(void) {
    int N, level;
    scanf("%d", &N);
    scanf("%s", player);
    if(strlen(player) == 1) {
        putchar('1'); return 0;
    }
    scanf("%s", judge);
    level = (int)log2(N);
    
    int winner = -1;
    
    // recursive
    winner = getWinner(0, N-1, level);

    // non-recursive
    int p1 = -1, p2 = -1, loser = -1;
    for(int lev = 1; lev <= level; lev++) {
        for(int i = 0; i < N; i++) {
            if(player[i] == 'n') continue;
            if(p1 == -1)
                p1 = i;
            else {
                p2 = i;
                loser = r_p_s(p1, p2, lev, 0);
                player[loser] = 'n';
                if(lev == level)
                    winner = loser==p2 ? p1 : p2;
                p1 = -1;
            }
        }
    }
    
    printf("%d", winner+1);
    return 0;
}

int r_p_s(int p1, int p2, int lev, int getwinner) {
    if(player[p1] == player[p2])
        return (judge[lev-1] == 'b') ^ getwinner ? p1 : p2;
    if(player[p1] == 'r')
        return (player[p2] == 'p') ^ getwinner ? p1 : p2;
    if(player[p1] == 'p')
        return (player[p2] == 's') ^ getwinner ? p1 : p2;
    if(player[p1] == 's')
        return (player[p2] == 'r') ^ getwinner ? p1 : p2;
    return -1;
}

int getWinner(int p1, int p2, int lev) {
    if(lev == 1)
        return r_p_s(p1, p2, lev, 1);
    int leftWinner = getWinner(p1, (p1+p2)/2, lev-1);
    int rightWinner = getWinner((p1+p2)/2+1, p2, lev-1);
    return r_p_s(leftWinner, rightWinner, lev, 1);
}
