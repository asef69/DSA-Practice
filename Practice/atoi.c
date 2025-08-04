#include<stdio.h>
#include<stdlib.h>
void mtoi(char *str,int *num){
    *num = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        *num = (*num * 10) + (*str - '0');
        str++;
    }

    *num *= sign;
}
int main(){
    int num;
    char *str=(char *)malloc(1000*sizeof(char));
    fgets(str,1000,stdin);
    mtoi(str,&num);
    printf("%d",num);
    free(str);
}
