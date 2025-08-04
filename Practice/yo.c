 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 int main()
 {
 clock_t start = clock();
 int a=5;
 while(a--){
    printf("Hello Asef!\n");
 }
 clock_t end = clock();
 double timediff = end- start;
 // clock time at the start
 // clock time at the end
 // difference between
 printf("%lf", timediff/CLOCKS_PER_SEC);
 return 0;
 }