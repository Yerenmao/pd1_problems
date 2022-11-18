#include <stdio.h>

void topLeft(int);
void topRight(int);
void bottomLeft(int);
void bottomRight(int);

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    switch(x) {
        case 1: topLeft(y); break;
        case 2: bottomLeft(y); break;
        case 3: topRight(y); break;
        case 4: bottomRight(y); break;
    }
    return 0;
}

void topLeft(int n) {
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < i; j++)
            putchar('*');
        putchar('\n');
    }
}

void topRight(int n) {
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < n-i; j++)
            putchar(' ');
        for(int j = 0; j < i; j++)
            putchar('*');
        putchar('\n');
    }
}

void bottomLeft(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) 
            putchar('*');
        putchar('\n');
    }
}

void bottomRight(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < n-i; j++)
            putchar(' ');
        for(int j = 0; j < i; j++)
            putchar('*');
        putchar('\n');
    }
}
