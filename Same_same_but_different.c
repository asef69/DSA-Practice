#include<stdio.h>
int main(){
    char s1[101],s2[101],s3[101];
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%s", s3);
    int len = strlen(s1);
     int count = 0;
    for (int i = 0; i < len; i++) {
      
        char a = s1[i], b = s2[i], c = s3[i];

        if (a == b && b == c) {
            continue;
        } else if (a == b || b == c || a == c) {
            count += 1;
        } else {
            count += 2;
        }
    }
    printf("%d",count);

}