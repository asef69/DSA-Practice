#include<stdio.h>
#include<stdlib.h>
void strncpy(char *dest,char *src,int n){
    while(*src!='\0'){
        *dest++=*src++;
    }
    while(n-->=0){
       *dest++='\0';
    }
}
int main(){
    int n; scanf("%d",&n);
    char *src=(char *) malloc(n*sizeof(char));
    char *dest=(char *) malloc(n*sizeof(char));
    for(int i=0;i<n;i++){
        scanf("%c",(src+i));
    }
    strncpy(dest,src,n);
    printf("%s",dest);
    free(dest);
    free(src);
}
