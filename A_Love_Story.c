#include<stdio.h>
#include<string.h>
int main(){
    int t; scanf("%d",&t);
    char s[]="codeforces";
    
    while(t--){
        int count=0;
        char c[11];
        scanf("%s",&c);
        for(int i=0;c[i]!='\0';i++){
            if(s[i]!=c[i]) count++;
        }
        printf("%d\n",count);
    }
    
}