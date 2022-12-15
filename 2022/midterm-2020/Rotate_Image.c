#include <stdio.h>

int pic[105][105];
int ans[105][105];

int main(void) {
    int degree; scanf("%d", &degree);
    int m, n; scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++) 
        for(int j = 0; j < n; j++) 
            scanf("%d", &pic[i][j]);
    if(degree == 90)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) 
                printf("%d ", pic[m-1-j][i]);
            printf("\n");
        }
    if(degree == 180) 
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) 
                printf("%d ", pic[m-1-i][n-1-j]);
            printf("\n");
        }
    if(degree == 270) 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) 
                printf("%d ", pic[j][n-1-i]);
            printf("\n");
        }
}
