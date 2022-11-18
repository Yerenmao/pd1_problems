#include <stdio.h>
#define SIZE 8

int card[SIZE][SIZE];
int bingo = 0;

void readCard(void);
void mark(int);
int checkRow(int);
int checkCol(int);
int checkDia(void);

int main(void) {
    readCard();
    int n;
    for(int i = 0; i < SIZE*SIZE; i++) {
        scanf("%d", &n); mark(n);
    }
    for(int i = 0; i < SIZE; i++)
        bingo += checkRow(i);
    for(int j = 0; j < SIZE; j++)
        bingo += checkCol(j);
    printf("%d", bingo + checkDia());
    return 0;
}

void readCard(void) {
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            scanf("%d", &card[i][j]);
}

void mark(int n) {
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if(card[i][j] == n)
                card[i][j] = 0;
}

int checkRow(int i) {
    for(int j = 0; j < SIZE; j++)
        if(card[i][j])
            return 0;
    return 1;
}

int checkCol(int j) {
    for(int i = 0; i < SIZE; i++)
        if(card[i][j])
            return 0;
    return 1;
}

int checkDia(void) {
    int main = 1, sub = 1;
    for(int k = 0; k < SIZE; k++) {
        if(card[k][k])
            main = 0;
        if(card[k][SIZE-k-1])
            sub = 0;
    }
    return main + sub;
}
