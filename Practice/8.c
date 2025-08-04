#include<stdio.h>
#include<ctype.h>
int main(){
    char s[100];
    fgets(s,sizeof(s),stdin);
    for(int i=0;s[i]!='\0';i++){
        printf("%c",toupper(s[i]));
    }
    printf("\n");
    for(int i=0;s[i]!='\0';i++){
        printf("%c",tolower(s[i]));
    }
}