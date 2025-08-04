#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);  // Read number of test cases
    
    while (t--) {
        char s[101];
        scanf("%s", s);  // Read the string s
        
        int len = strlen(s);
        
        // If the length of the string is odd, it's automatically not square
        if (len % 2 != 0) {
            printf("NO\n");
        } else {
            // Split the string into two halves and check if they are identical
            int mid = len / 2;
            if (strncmp(s, s + mid, mid) == 0) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    
    return 0;
}
