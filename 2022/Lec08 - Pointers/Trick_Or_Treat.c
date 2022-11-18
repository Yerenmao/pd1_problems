/*
 * [Loader Code]
#include<stdio.h>
#include<stdlib.h>
int array[1500];
int maxChandy( int size) ;
int main() {
    int size = 0;
    scanf("%d", &size);
    for(int i = 0 ; i < size; ++i) {
        scanf("%d", &array[i]);
    }
    printf("%d\n", maxChandy( size));
    return 0;
}
*/

int max(int a, int b) {
    return a > b ? a : b;
}

int search(int idx, int size) {
    if(idx >= size)
        return 0;
    int sidx2 = search(idx+2, size);
    int sidx3 = search(idx+3, size);
    return max(sidx2, sidx3) + ((idx == -2) ? 0 : array[idx]);
}

int maxCandy(int s) {
    if(s == 0) return array[0];
    if(s == 1) return array[1];
    if(s == 2) return array[0] + array[2];
    return max(maxCandy(s-2), maxCandy(s-3)) + array[s];
}

int dpCandy(int size) {
    int candy[1500] = {
        array[0], array[1], array[0]+array[2]
    };
    for(int i = 3; i < size; i++)
        candy[i] = max(candy[i-2], candy[i-3]) + array[i];
    return max(candy[size-1], candy[size-2]);
}

int maxChandy(int size) {
    int method = 3;
    switch(method) {
        case 1:     // recursive
            return search(-2, size);
        case 2:     // recursive
            return size == 1 ? array[0] : max(maxCandy(size-1), maxCandy(size-2));
        case 3:     // non-recursive
            return dpCandy(size);
    }
    return 0;
}
