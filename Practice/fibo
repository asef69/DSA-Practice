#include <stdio.h>
#include <stdbool.h>

bool fibonacci(int n) {
    int first = 0, second = 1;
    int next;

    // Handle special case for 0
    if (n == 0) return true;

    // Generate Fibonacci numbers and check if n is one of them
    while (second <= n) {
        if (n == second) return true;
        next = first + second;
        first = second;
        second = next;
    }
    return false;
}

int add(int n) {
    int first = 0, second = 1;
    int next = 0, sum = first + second;

    // Sum Fibonacci numbers until they exceed n
    while (next <= n) {
        next = first + second;
        first = second;
        second = next;
        if (next <= n) {
            sum += next;
        }
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);

    if (fibonacci(n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    printf("%d", add(n));
    return 0;
}
