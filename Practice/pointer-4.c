#include<stdio.h>
#include<string.h>
void mystrcpy(char* c,char *d){
    int length=strlen(c);
    for(int i=0;*(c+i)!='\0';i++){
        *(d+i)=*(c+i);
    }
    printf("%s",d);
    free(c);
    free(d);
}
int main(){
    char *c=(char *)malloc(100*sizeof(char));
    scanf("%s",c);
    char *d=(char *)malloc(100*sizeof(char));
    mystrcpy(c,d);
}
