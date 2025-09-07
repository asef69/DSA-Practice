#include<stdio.h>
#include<string.h>
int main(){
    char c[100000];
    scanf("%s",&c);
    int h[26]={0};
    for(int i=0;c[i]!='\0';i++){
        h[c[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(h[i]>0){
            printf("%c : %d\n",i+'a',h[i]);
        }
    }
}