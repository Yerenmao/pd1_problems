#include <stdio.h>

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);
    int arr1[m], arr2[n];
    for(int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }
    int idx1 = 0, idx2 = 0;
    while(idx1 < m || idx2 < n) {
        if(idx1 >= m) {
            printf("%d ", arr2[idx2]); idx2++; continue;
        }
        if(idx2 >= n) {
            printf("%d ", arr1[idx1]); idx1++; continue;
        }
        if(arr1[idx1] < arr2[idx2]) {
            printf("%d ", arr1[idx1]); idx1++; continue;
        }
        if(arr1[idx1] > arr2[idx2]) {
            printf("%d ", arr2[idx2]); idx2++; continue;
        }
    }
    return 0;
}
