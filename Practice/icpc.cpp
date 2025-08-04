#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        string s;
        cin >> n >> s; // Read the number of solved problems and the string of solved problems

        unordered_set < char > solvedProblems; // Set to track solved problems
        int totalBalloons = 0; // Variable to store the total number of balloons

        for (char problem : s) {
            if (solvedProblems.find(problem) == solvedProblems.end()) {
                // If the problem has not been solved yet, give 2 balloons
                totalBalloons += 2;
                solvedProblems.insert(problem); // Mark this problem as solved
            } else {
                // If the problem has been solved before, give only 1 balloon
                totalBalloons += 1;
            }
        }

        cout << totalBalloons << endl; // Output the total number of balloons for this test case
    }

    return 0;
}
