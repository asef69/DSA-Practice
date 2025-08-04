#include <stdio.h>
#include <string.h>

int main() {
    int t;
    // Read the number of test cases
    scanf("%d", &t);

    // Define the string "codeforces" to check against
    char codeforces[] = "codeforces";

    // Process each test case
    while (t--) {
        char c;
        // Read the character for this test case
        scanf(" %c", &c);

        // Check if the character exists in the string "codeforces"
        if (strchr(codeforces, c)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
