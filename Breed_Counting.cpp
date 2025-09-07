#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q; // Number of cows and number of queries

    vector<int> breed1(N + 1, 0); // Prefix sum for Holsteins (breed 1)
    vector<int> breed2(N + 1, 0); // Prefix sum for Guernseys (breed 2)
    vector<int> breed3(N + 1, 0); // Prefix sum for Jerseys (breed 3)

    // Read breed IDs and compute prefix sums
    for (int i = 1; i <= N; ++i) {
        int breed;
        cin >> breed;

        breed1[i] = breed1[i - 1];
        breed2[i] = breed2[i - 1];
        breed3[i] = breed3[i - 1];

        if (breed == 1) breed1[i]++;
        else if (breed == 2) breed2[i]++;
        else if (breed == 3) breed3[i]++;
    }

    // Process queries
    while (Q--) {
        int a, b;
        cin >> a >> b;

        // Calculate counts for each breed in range [a, b]
        int count1 = breed1[b] - breed1[a - 1];
        int count2 = breed2[b] - breed2[a - 1];
        int count3 = breed3[b] - breed3[a - 1];

        // Output results for the current query
        cout << count1 << " " << count2 << " " << count3 << "\n";
    }
}