#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char str[200];
    fgets(str,sizeof(str),stdin);
    char  new[200];
    int index=0,i=0;
    while(str[i]!='\0'){
        if(!isspace(str[i])){
            new[index++]=str[i];
        }
        else if(index>0){
            new[index]='\0';
            printf("%s\n",new);
            index=0;
        }
        i++;
    }
    if(index>0){
            new[index]='\0';
            printf("%s",new);
        }
}