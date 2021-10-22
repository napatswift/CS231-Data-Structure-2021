#include <stdio.h>

int palindrome(char *string){
    int len = 0;
    char *c = string;
    while(*c!='\0'){
        c++;
        len++;
    }
    for(int i = 0; i < len/2; i++)
        if (string[i] != string[len-1-i])
            return 0;
    return 1;
}

int main(){
    int line;
    char string[100];
    scanf("%d", &line);
    for(int i = 0; i < line; i++){
        scanf("%s", string);
        printf("%s Is%s Palindrome.\n", string, palindrome(string) ? "" : " Not");
    }
    return 0;
}
