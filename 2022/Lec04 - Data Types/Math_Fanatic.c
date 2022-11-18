#include <stdio.h>

typedef unsigned long long ll;

int main(void) {
    int n;
    scanf("%d", &n);
    ll prefixSum = 0; int num;
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        prefixSum += num;
        if(prefixSum % num == 0)
            printf("%llu %d\n", prefixSum, num);
    }
    return 0;
}
