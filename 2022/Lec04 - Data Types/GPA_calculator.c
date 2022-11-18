#include <stdio.h>

int main(void) {
    double point = 0, credit = 0, totalPoint = 0, totalCredit = 0;
    char ch;
    while(1) {
        ch = getchar();
        if(('0' <= ch && ch <= '9') || ch == '\n') {
            totalPoint += point * credit;
            totalCredit += credit;
            if(ch == '\n') break;
            credit = ch - '0';
        } else if(('A' <= ch && ch <= 'Z') || ch == '+' || ch == '-') {
            switch(ch) {
                case 'A': point = 4.0; break;
                case 'B': point = 3.0; break;
                case 'C': point = 2.0; break;
                case 'F': point = 0; break;
                case '+': point += 0.3; break;
                case '-': point -= 0.3; break;
            }
        }
    }
    printf("%.2f", totalPoint/totalCredit);
    return 0;
}
