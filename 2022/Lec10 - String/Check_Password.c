/*
* [Loader Code]
# include <stdio.h>
# include <string.h>

#define SIZE 25

int length(char pwd1[], char pwd2[]);

int compare(char pwd1[], char pwd2[]);

int content(char pwd1[]);

int main()
{
    char password1[SIZE];
    char password2[SIZE];
    
    // Enter the password
    scanf("%s", password1);
    // Enter the password again
    scanf("%s", password2);
    
    // Check Password
    // First: Check length
    if(length(password1, password2) == 1) {
        printf("Length does not match the requirements");
    }
    else {
        // Second: Check for consistency
        if(compare(password1, password2) == 1) {
            printf("Not the same password");
        }
        else {
            // Third: Check for compliance
            if(content(password1) == 1) {
                printf("Do not satisfy the conditions");
            }
            else {
                printf("Everything is good");
            }
        }
    }

    return 0;
}
*/

int length(char *pwd1, char *pwd2) {
    int l1 = (int)strlen(pwd1), l2 = (int)strlen(pwd2);
    if(! (6 <= l1 && l1 <= 16 && 6 <= l2 && l2 <= 16) )
        return 1;
    return 0;
}

int compare(char *pwd1, char *pwd2) {
    if(strcmp(pwd1, pwd2)) 
        return 1;
    return 0;
}

int content(char *pwd1) {
    int upper = 0, lower = 0, number = 0, correct = 0;
    for(char *c = pwd1; *c != '\0'; c++) {
        if(!upper && 'A' <= *c && *c <= 'Z')
            upper = 1;
        if(!lower && 'a' <= *c && *c <= 'z')
            lower = 1;
        if(!number && '0' <= *c && *c <= '9')
            number = 1;
        if(upper & lower & number) {
            correct = 1; break;
        }
    }
    if(!correct)
        return 1;
    return 0;
}

