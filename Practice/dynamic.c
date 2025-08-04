#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int *array = (int *)malloc(sizeof(int));
    if (array == NULL) {

        return 1;
    }

    int currentSize = 1; 
    int count = 0;       

    
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);

        
        if (count >= currentSize) {
            currentSize *= 2; 
            int *temp = realloc(array, currentSize * sizeof(int));
            if (temp == NULL) {
                free(array); 
      
                return 1;
            }
            array = temp; 
        }

        
        array[count++] = num;
    }

    for (int i = 0; i < count; i++) {
        printf("%d", array[i]);
        if (i < count - 1) {
            printf(" "); 
        }
    }
    printf("\n");

   
    free(array);

    return 0;
}
