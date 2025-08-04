#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int a; cin>>a;
        int arr[a+1];
        for(int i=0; i<a; i++){
            cin>>arr[i];
        }
        for(int i=1;i<a;i++){
            int m=min(arr[i],arr[i-1]);
            arr[i-1]-=m;
            arr[i]-=m;
        }
        int flag=1;
        for(int i=0;i<a-1;i++){
            if(arr[i]<arr[i-1]){
                
                flag=0;
                break;
            }
        }
        cout<<(flag?"YES":"NO")<<endl;
    }
}