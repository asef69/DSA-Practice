#include<stdio.h>
#include<string.h>
void check(char *a, char *b){
    int len=strlen(a);
    for(int i=0;a[i]!='\0';i++){
        if(a[i]>b[i]) {
            printf("1\n");
            return;
            }
        else if(a[i]<b[i]) {
            printf("-1\n");
            return;
        }
    }
}
int main(){
    char a[100],b[100];
    scanf("%s",&a);
    scanf("%s",&b);
    int len1=strlen(a);
    int len2=strlen(b);
    if(len1>len2) printf("1\n");
    else if(len2>len1) printf("-1\n");
    else{
        check(a,b);
    }
}