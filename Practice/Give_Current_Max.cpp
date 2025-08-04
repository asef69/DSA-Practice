#include<bits/stdc++.h>
using namespace std;

class student{
public:
    string name;
    int roll, marks;
    
    student(string name, int roll, int marks) {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class cmp{
public:
    bool operator()(student a, student b) {
        if(a.marks == b.marks) {
            return a.roll > b.roll;  // If marks are equal, compare roll numbers
        }
        return a.marks < b.marks;  // Compare marks in descending order
    }
};

int main() {
    int n;
    cin >> n;

    priority_queue<student, vector<student>, cmp> pq;
    
    for(int i = 0; i < n; i++) {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        student s(name, roll, marks);
        pq.push(s);
    }

    int k;
    cin >> k;

    while(k--) {
        int x;
        cin >> x;
        if(x == 0) {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            student q(name, roll, marks);
            pq.push(q);
            if (!pq.empty()) {
                student a = pq.top();
                cout << a.name << " " << a.roll << " " << a.marks << endl;
            }
        } 
        else if(x == 1) {
            if (!pq.empty()) {
                student b = pq.top();
                cout << b.name << " " << b.roll << " " << b.marks << endl;
            } else {
                cout << "Empty" << endl;
            }
        } 
        else if(x == 2) {
            if (!pq.empty()) {
                pq.pop();
                if (pq.empty()) {
                    cout << "Empty" << endl;
                } else {
                    student c = pq.top();
                    cout << c.name << " " << c.roll << " " << c.marks << endl;
                }
            } else {
                cout << "Empty" << endl;
            }
        }
    }

    return 0;
}
