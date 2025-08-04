#include <bits/stdc++.h>
using namespace std;

class student {
public:
    string nm;
    int cls;
    char s;
    int id;
    int math;
    int eng;
    int total;
};

bool cmp(student l, student r) {
    if (l.total == r.total) return l.id < r.id;  
    return l.total > r.total; 
}

int main() {
    int n;
    cin >> n;  
    student a[n];  
    for (int i = 0; i < n; i++) {
        cin >> a[i].nm >> a[i].cls >> a[i].s >> a[i].id >> a[i].math >> a[i].eng;
        a[i].total = a[i].math + a[i].eng; 
    }
    sort(a, a+n, cmp);
    for (int i=0;i<n;i++) {
        cout << a[i].nm << " " << a[i].cls << " " << a[i].s << " " 
             << a[i].id << " " << a[i].math << " " << a[i].eng << endl;
    }

    return 0;
}