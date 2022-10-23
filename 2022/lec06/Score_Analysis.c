#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int score[n];
    for(int i = 0; i < n; i++) 
        scanf("%d", &score[i]);
    
    int t;
    scanf("%d", &t);
    int interval[t][5];
    for(int i = 0; i < t; i++) {
        scanf("%d%d", &interval[i][0], &interval[i][1]);
        interval[i][2] = interval[i][3] = interval[i][4] = 0;
    }

    for(int i = 0; i < t; i++) {
        for(int j = 0; j < n; j++) {
            if(score[j] < interval[i][0]) 
                interval[i][2]++;
            else if(interval[i][0] <= score[j] && score[j] < interval[i][1])
                interval[i][3]++;
            else
                interval[i][4]++;
        }
    }
    
    for(int i = 0; i < t; i++) {
        printf("%d %d %d\n", interval[i][2], interval[i][3], interval[i][4]);
    }
    return 0;
}
