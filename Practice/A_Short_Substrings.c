#include <stdio.h>
#include <string.h>

int main() {
    int t;
    // Read the number of test cases
    scanf("%d", &t);

    while (t--) {
        char b[101];
        // Read the string b for the current test case
        scanf("%s", b);

        int len_b = strlen(b);
        // Start forming the string a from b
        char a[101];
        int index = 0;
        
        // First character of a is the first character of b
        a[index++] = b[0];
        
        // Process the rest of the string b
        for (int i = 1; i < len_b; i += 2) {
            a[index++] = b[i];
        }
        
        // Null-terminate the string a
        a[index] = '\0';

        // Output the resulting string a
        printf("%s\n", a);
    }

    return 0;
}
