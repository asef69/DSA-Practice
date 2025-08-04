#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void compressString(char *c)
{
    char *d=(char *)malloc(500*sizeof(char));
    char e=*c;
    int count=0;
    char *result=d;
    for(int i=0; *(c+i)!='\0'; i++)
    {
        if(*(c+i)==e) count++;
        else
        {

            *(result+i-1)=e;
            printf("%c%d",e,count);
            count=1;
            e=*(c+i);
        }
        *(c+i)='\0';
    }
    printf("%c%d",e,count);
    if(strlen(c)<=strlen(d))
    {
        printf("%s",c);
    }
    else
    {
        printf("%s",d);
    }
    free(d);

}
int main()
{
    char *c=(char *)malloc(100*sizeof(char));
    scanf("%s",c);

    compressString(c);

    free(c);

    return 0;
}
