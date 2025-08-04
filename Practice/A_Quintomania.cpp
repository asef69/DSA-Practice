#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read the number of test cases (melodies)
    
    while (t--) {
        int n;
        cin >> n;  // Number of notes in the melody
        
        vector<int> notes(n);
        for (int i = 0; i < n; i++) {
            cin >> notes[i];  // Read each note in the melody
        }
        
        bool isPerfect = true;
        
        for (int i = 1; i < n; i++) {
            int interval = abs(notes[i] - notes[i - 1]);
            if (interval != 5 && interval != 7) {
                isPerfect = false;
                break;  // No need to check further if one interval is incorrect
            }
        }
        
        cout << (isPerfect ? "YES" : "NO") << endl;
    }
    
    return 0;
}
