#include <stdio.h>
#include <string.h>
#define CMD_MAX 25

int won = 0, movement = 0, cor_cmd = 0, def = 0, dis, hp;

int do_command(char *command) {
    movement++;
    if(strcmp(command, "PATA PATA PATA PON") == 0) {
        cor_cmd++; def = 0; dis--;
        if(!dis) return 1;
    }
    if(strcmp(command, "PON PON PATA PON") == 0) {
        cor_cmd++; def = 0;
        if(dis <= 3) {
            hp--;
            if(!hp) {won = 1; return 1;}
        }
    }
    if(strcmp(command, "CHAKA CHAKA PATA PON") == 0) {
        cor_cmd++; dis++; def = 1;
    }
    if(movement % 10 == 0) {
        if(!def) return 1;
        if(movement == 30) return 1;
    }
    return 0;
}

int main(void) {
    scanf("%d %d", &dis, &hp); getchar();
    char ch; char command[CMD_MAX]; int idx = 0;
    while(1) {
        ch = getchar();
        if(ch == '.' || ch == ',' || ch == '\n') {
            command[idx] = '\0';
            if(do_command(command))
                break;
            idx = 0;
            continue;
        }
        if(idx < CMD_MAX) {
            command[idx] = ch; idx++;
        }
    }
    if(won) printf("YES %d", cor_cmd);
    else printf("NO %d", hp);
    return 0;
}
