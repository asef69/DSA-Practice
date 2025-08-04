#include<bits/stdc++.h>
using namespace std;
bool elimination(string &s){
    stack<char>final_result;
    for(char c:s){
    if(c=='1'&& !final_result.empty() && final_result.top()=='0'){
        final_result.pop();
    }
    else{
        final_result.push(c);
    }
    }
    return final_result.empty();
}
int main (){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(elimination(s)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}