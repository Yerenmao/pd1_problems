/*
* [Loader Code]
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 4096

void recovery(char *homework);

int main () {
    char homework[MAX_LEN + 1];
    
    // Get the homework content.
    fgets(homework, MAX_LEN , stdin);
    recovery(homework);

    // Print the recovered homework.
    fputs(homework, stdout);

    return 0;
}
*/

void recovery(char *homework) {
    char *word, recovered_homework[MAX_LEN + 1] = {'\0'};
    for(word = strtok(homework, " \n"); word; word = strtok(NULL, " ")) {
        int valid = 1, end = 0;
        if(strlen(word) > 21)
            valid = 0;
        if(valid) {
            for(int i = 0; word[i] != '\0'; i++) {
                if(isalpha(word[i]))
                    continue;
                if(word[i] == ',' || word[i] == '.' || word[i] == '!' || word[i] == '?') {
                    if(strlen(word) == 1) 
                        {valid = 0; break;}
                    if(word[i+1] == '\n') 
                        {end = 1; break;}
                    if(word[i+1] == '\0')
                        break;
                    valid = 0; break;
                }
                valid = 0; break;
            }
        }
        if(valid) {
            strcat(recovered_homework, word);
            if(!end)
                strcat(recovered_homework, " ");
        }
    }
    strcpy(homework, recovered_homework);
}
