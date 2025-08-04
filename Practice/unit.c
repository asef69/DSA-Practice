#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int a[N][N];
    
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    

    int flag = 1; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
               
                if (a[i][j] != 1) {
                    flag = 0; 
                    break;
                }
            } else {
               
                if (a[i][j] != 0) {
                    flag = 0; 
                    break;
                }
            }
        }
        if (!flag) break; 
    }
    
    
    if (flag) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
