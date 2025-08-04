#include<bits/stdc++.h>
using namespace std;
void print(long long int a){
    if(a==0) return;
    print(a/10);
    cout<<a%10<<" ";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int a;
        cin>>a;
        if(a==0) cout<<0<<endl;
        else{
        print(a);
        cout<<endl;
        }
    }
}