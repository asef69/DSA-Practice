#include<stdio.h>
#include<string.h>
void extraspace(char *text){
    int j=0;
    int space=0;
    for(int i=0;i<strlen(text);i++){
        if(text[i]!=' '){
            text[j++]=text[i];
            space=0;
        }
        else if(!space){
            text[j++]=' ';
            space=1;
        }
    }
    text[j]='\0';
    printf("%s",text);
}
int main(){
    char string[300];
    printf("Enter the string:");
    fgets(string,sizeof(string),stdin);
    extraspace(string);
}