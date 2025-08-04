#include <stdio.h>
#include <string.h>

void replaceSubstring(char *s1, const char *s2, const char *s3) {
    int i, j, k;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    int count = 0;
    char result[1000]; 
    int resultIndex = 0;
    
    
    for (i = 0; i < len1; i++) {
        
        if (s1[i] == s2[0]) {
            
            for (j = 0; j < len2; j++) {
                if (s1[i + j] != s2[j]) {
                    break;
                }
            }
            
           
            if (j == len2) {
                
                for (k = 0; k < len3; k++) {
                    result[resultIndex++] = s3[k];
                }
                
                i += len2 - 1;
                count++;  
            } else {
                
                result[resultIndex++] = s1[i];
            }
        } else {
            
            result[resultIndex++] = s1[i];
        }
    }
    
    
    result[resultIndex] = '\0';
    
   
    printf("Resulting string: %s\n", result);
    printf("Number of replacements: %d\n", count);
}

int main() {
    char s1[1000], s2[100], s3[100];
    
    
    printf("Enter the first string (s1): ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = 0;  
    
    printf("Enter the second string (s2): ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = 0;  
    
    printf("Enter the third string (s3): ");
    fgets(s3, sizeof(s3), stdin);
    s3[strcspn(s3, "\n")] = 0;  
    
   
    replaceSubstring(s1, s2, s3);
    
    return 0;
}
