/*
* [Loader Code]
#include <stdio.h>
#define ARR_MAX 1000
void sort_section(int *ptr, int *qtr);
int main() {
  int N, a, b;
  scanf("%d%d%d", &N, &a, &b);
  int arr[ARR_MAX] = {0};
  for (int i = 0; i < N; i++) {
    scanf("%d", arr + i);
  }
  sort_section(&arr[a], &arr[b]);
  for (int i = 0; i < N; i++) {
    printf("%d ", *(arr + i));
  }
}
*/

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void print_sec(int *l, int *r) {
    for(int *p = l; p != r + 1; p++)
        printf("%d ", *p);
    printf("\n");
}

void sort_section(int *ptr, int *qtr) {
    int *l, *r;
    if(ptr > qtr) {l = qtr; r = ptr;}
    else {l = ptr; r = qtr;}

    for(int *end = r; end != l; end--) {
        for(int *cur = l; cur != end; cur++) 
            if(*cur > *(cur+1))
                swap(cur, cur+1);
        print_sec(l, r);
    }
}
