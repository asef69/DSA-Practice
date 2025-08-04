#include<stdio.h>
#include<string.h>
int main(){
    char s[80];
    fgets(s,80,stdin);
    char c[80];
    int index;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='a'|| s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {            
            continue;}
        else c[index++]=s[i];
    }
    c[index]='\0';
    printf("%s",c);
}