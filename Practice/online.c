#include <stdio.h>
#include <limits.h>

int findMaxProfit(int stocks[], int n) {
    int max_current = stocks[0];
    int max_global = stocks[0];

    for (int i = 1; i < n; i++) {
        // At each step, decide whether to include the current element in the existing subarray or start a new subarray
        if (max_current < 0) {
            max_current = stocks[i];
        } else {
            max_current += stocks[i];
        }

        if (max_current > max_global) {
            max_global = max_current;
        }
    }

    return max_global;
}

int main() {
    int n;
    scanf("%d", &n);

    int stocks[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stocks[i]);
    }

    int maxProfit = findMaxProfit(stocks, n);
    printf("%d\n", maxProfit);

    return 0;
}

