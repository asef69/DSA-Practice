#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    
    while (t--) {
        string sentence;
        getline(cin, sentence);

        map<string, int> wordCount;
        vector<string> wordOrder;
        stringstream ss(sentence);
        string word;
        int maxCount = 0;
        string mostFrequentWord;
        while (ss >> word) {
            if (wordCount[word] == 0) {
                wordOrder.push_back(word);
            }
            wordCount[word]++;
            if (wordCount[word] > maxCount && wordCount[word] != maxCount ) {
                maxCount = wordCount[word];
                mostFrequentWord = word;
            }
        }

        cout << mostFrequentWord << " " << maxCount << endl;
    }

    return 0;
}
