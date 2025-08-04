#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int numberstring(const char *str){
    if(*str=='\0') return 0;
    while(*str){
        if(!isdigit(*str)) return 0;
         str++;
    }
    return 1;
}
int main(){
    char str[100];
    printf("Numeric string:");
    scanf("%s",&str);
    if(numberstring(str)){
        int number=atoi(str);
        printf("Integer number:%d",number);
    }
    else{
        printf("Invalid input");
    }
}