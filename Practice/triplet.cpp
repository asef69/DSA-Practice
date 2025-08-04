#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n<3){
            cout<<"Invalid Input"<<endl;
            continue;
        }
        int maximum=INT_MIN;
        int j=1,index=0,last=0;
        for(int i=0;i<n-2;i++){
            if(arr[i]+arr[j]+arr[j+1]>maximum){
                index=i;
                last=i+2;
                maximum=arr[i]+arr[j]+arr[j+1];
            }
            j++;
        }
        for(int i=index;i<last+1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}