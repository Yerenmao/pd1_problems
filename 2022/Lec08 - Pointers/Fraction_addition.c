/*
 * [Loader Code]
#include <stdio.h>
void fraction_adder(int a_numerator, int a_denominator, int b_numerator,
              int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr);
int main() {
  int a_numerator, a_denominator, b_numerator, b_denominator;
  scanf("%d%d%d%d", &a_numerator, &a_denominator, &b_numerator, &b_denominator);
  int c_numerator, c_denominator;
  fraction_adder(a_numerator, a_denominator, b_numerator, b_denominator, &c_numerator,
           &c_denominator);
  printf("%d/%d\n", c_numerator, c_denominator);
}
*/

int gcd(int a, int b) {
    int max = 0;
    for(int i = 1; i <= a && i <= b; i++)
        if(a % i == 0 && b % i == 0)
            max = i;
    return max;
}

void fraction_adder(int a_numerator, int a_denominator, int b_numerator, int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr) {
    int t = a_numerator * b_denominator + b_numerator * a_denominator;
    int b = a_denominator * b_denominator;
    int s = gcd(t, b);
    *c_numerator_ptr = t / s;
    *c_denominator_ptr = b / s;
}
