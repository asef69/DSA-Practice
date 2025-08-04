#include<bits/stdc++.h>
using namespace std;
student bool cmp(student l, student r){
    if(l.total>r.total) return true;
    else return false;
}
bool cm(student l, student r){
    if(l.id>r.id) return true;
    else return false;
}
class student{
public:
    string nm;
    char s;
    int math,eng,total;
};
int main(){
    int n; cin>>n;
    student a[n];
    int total[n];
    for(int i=0;i<n;i++){
        cin>>a[i].nm>>a[i].cls>>a[i].s>>a[i].id>>a[i].math>>a[i].eng;
        a[i].total=a[i].math+a[i].eng;
    }
    sort(a,a+n,cmp);
    sort(a,a+n,cm);
    student mn;
    mn.total=INT_MIN;
    mn.id=INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i].total>mn.total){
            mn=a[i];
        }
        else if(a[i].total==mn.total){
            if(a[i].id>mn.id) mn=a[i];
        }
        cout<<mn.nm<<mn.cls<<mn.s<<mn.math<<mn.eng<<endl;
    }

}
