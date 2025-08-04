#include <stdio.h>

int main() {
    int count = 0; // Count of prime numbers found
    int num = 2;   // Starting number to check for primality

    printf("First 1000 prime numbers:\n");

    while (count < 1000) {
        int is_prime = 1; // Assume the number is prime

        // Check if num is prime
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                is_prime = 0; // Not prime
                break;
            }
        }

        if (is_prime) {
            printf("%d ", num);
            count++;
        }

        num++;
    }

    printf("\n");
    return 0;
}
