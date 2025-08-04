#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
    string S,X;
     getline(cin, S);
        getline(cin, X);


        size_t pos = 0;
        while ((pos = S.find(X, pos)) != string::npos) {
            S.replace(pos, X.length(), "#");
            pos += 1;
        }

        cout << S << endl;
    }
    }

