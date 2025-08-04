#include<stdio.h>
#include<stdlib.h>
void change(char *str,float *num){
     *num = 0.0f;
    float sign = 1.0f;
    float fraction = 0.0f;
    int divisor = 1;

    if (*str == '-') {
        sign = -1.0f;
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        *num = (*num * 10) + (*str - '0');
        str++;
    }

    if (*str == '.') {
        str++;
        while (*str >= '0' && *str <= '9') {
            fraction = (fraction * 10) + (*str - '0');
            divisor *= 10;
            str++;
        }
    }

    *num += fraction / divisor;
    *num *= sign;
}
int main(){
    float num; scanf("%f",&num);
    char *str=(char *)malloc(1000*sizeof(char));
    change(str,&num);
    printf("%s",str);
    free(str);
}
