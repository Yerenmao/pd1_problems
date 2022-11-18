#include <stdio.h>
#define BYTE_NUM 4

unsigned int getByte(unsigned int num, int n) {
    return 0x000000ff & (num >> 8 * (BYTE_NUM - n));
}

void putByte(unsigned int *temp, int num, int n) {
    *temp = *temp | (num << 8 * (BYTE_NUM - n));
}

void rotate(unsigned int *temp, int n) {
    *temp = (*temp >> n) | (*temp << (8*BYTE_NUM - n));
}

int main(void) {
    unsigned int num, temp = 0x00000000;
    int d1, d2, d3, d4;
    scanf("%ud", &num);
    scanf("%d %d %d %d", &d1, &d2, &d3, &d4);
    putByte(&temp, getByte(num, d1) ^ getByte(num, d2), 1);
    putByte(&temp, getByte(num, d2) & getByte(num, d3), 2);
    putByte(&temp, getByte(num, d3) | getByte(num, d1), 3);
    putByte(&temp, getByte(num, d4) ^ 0x000000ff, 4);
    rotate(&temp, d1 + d2 + d3 + d4);
    temp = (temp >> 16) ^ (temp & 0x0000ffff);
    printf("%u\n", temp);
    return 0;
}
