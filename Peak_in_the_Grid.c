#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    int peakCount = 0; // Number of mountain peaks

    // Iterate through the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int isPeak = 1; // Assume current cell is a peak

            // Check top neighbor
            if (i > 0 && a[i][j] <= a[i - 1][j]) isPeak = 0;
            // Check bottom neighbor
            if (i < n - 1 && a[i][j] <= a[i + 1][j]) isPeak = 0;
            // Check left neighbor
            if (j > 0 && a[i][j] <= a[i][j - 1]) isPeak = 0;
            // Check right neighbor
            if (j < m - 1 && a[i][j] <= a[i][j + 1]) isPeak = 0;

            // If it's a peak, print its position and increment count
            if (isPeak) {
                printf("%d %d\n", i + 1, j + 1); // 1-based position
                peakCount++;
            }
        }
    }

    // Print the number of peaks
    printf("%d\n", peakCount);

    return 0;
}
