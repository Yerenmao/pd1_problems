/*
* [Loader Code]
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_LEN 1024
#define LINE_LEN 128

void convert(char *arr[], int count);
int main() {
  char line[BUFFER_LEN];
  char buffer[LINE_LEN][BUFFER_LEN];
  char *arr[LINE_LEN];

  int count = 0;
  while (fgets(line, BUFFER_LEN - 1, stdin) != NULL) {
    arr[count] = buffer[count];
    strncpy(buffer[count++], line, BUFFER_LEN - 1);
  }
  convert(arr, count);
  for (int i = 0; i < count; i++) {
    printf("%s", arr[i]);
  }
}
*/


void convert(char *arr[], int count) {
    char new[BUFFER_LEN] = {0}; char num[5] = {0};
    int n, pos, times;
    for(int i = 0; i < count; i++) {
        for(char *c = arr[i]; *c != '\n'; c++) {
            if('a' <= *c && *c <= 'z') {
                n = *c - 'a'; num[0] = '('; num[2] = ')';
                if(0 <= n && n <= 14) {
                    pos = 2 + n / 3; times = 1 + n % 3;
                }
                if(15 <= n && n <= 18) {
                    pos = 7; times = n - 14;
                }
                if(19 <= n && n <= 21) {
                    pos = 8; times = n - 18;
                }
                if(22 <= n && n <= 25) {
                    pos = 9; times = n - 21;
                }
                num[1] = '0'+pos; num[3] = '0'+times; num[4] = '\0';
                strcat(new, num);
            } else
                strcat(new, " ");
        }
        strcat(new, "\n");
        strcpy(arr[i], new);
        memset(new, '\0', BUFFER_LEN);
    }
}


