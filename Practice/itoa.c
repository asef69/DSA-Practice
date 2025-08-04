#include<stdio.h>
#include<stdlib.h>
void change(char *str,int *num){
    int n = *num;
    int sign = n < 0 ? -1 : 1;
    n = n * sign;
    char *start = str;

    do {
        *str++ = '0' + (n % 10);
        n /= 10;
    } while (n > 0);

    if (sign < 0) *str++ = '-';

    *str = '\0';
    char *end = str - 1;
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}
int main(){
    int num; scanf("%d",&num);
    char *str=(char *)malloc(1000*sizeof(char));
    change(str,&num);
    printf("%s",str);
    free(str);
}
