#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    list<int> myList; 
    
    while(n--) {
        int x, v;
        cin >> x >> v;
        
        if(x == 0) {
            
            myList.push_front(v);
        }
        else if(x == 1) {
            
            myList.push_back(v);
        }
        else if(x == 2) {
            
            if(v >= 0 && v < myList.size()) {
                auto it = myList.begin();
                advance(it, v); 
                myList.erase(it); 
            }
        }

        
        cout << "L -> ";
        for(int i : myList) {
            cout << i << " ";
        }
        cout << endl;

        cout << "R -> ";
        for(auto it = myList.rbegin(); it != myList.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    
    return 0;
}
