#include<bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    vector<int> v(26, 0); // Initialize vector with 26 zeros for each letter of the alphabet

for (int i = 0; i < s.size(); i++) {
    v[s[i] - 'a']++;
}

for (int i = 0; i < 26; i++) {
    if (v[i] > 0) {
        cout << char(i + 'a') << " : " << v[i] << endl;
    }
}

}
