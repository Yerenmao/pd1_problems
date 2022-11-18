#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int score[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &score[i]);
    int T, left, right, l, m, r;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        l = m = r = 0;
        scanf("%d %d", &left, &right);
        for(int j = 0; j < N; j++) {
            if(score[j] < left)
                l++;
            else if(left <= score[j] && score[j] < right)
                m++;
            else
                r++;
        }
        printf("%d %d %d\n", l, m, r);
    }
    return 0;
}
