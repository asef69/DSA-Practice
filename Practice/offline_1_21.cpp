#include <bits/stdc++.h>
using namespace std;

class Student {
private:
    int roll;
    string name;
    float cgpa;

public:
    Student() {
        roll = 0;
        cgpa = 0.0;
        name = "";
    }

    Student(string name) {
        this->name = name;
        this->roll = 0;
        this->cgpa = 0.0;
    }

    Student(int roll) {
        this->roll = roll;
        this->name = "";
        this->cgpa = 0.0;
    }
    Student(float cgpa) {
        this->roll = 0;
        this->name = "";
        this->cgpa = cgpa;
    }

    Student(int roll, string name, float cgpa) {
        this->name = name;
        this->roll = roll;
        this->cgpa = cgpa;
    }

    ~Student() {
        roll = 0;
    }

    void setname(string name) {
        this->name = name;
    }

    void setroll(int roll) {
        this->roll = roll;
    }

    void setcg(float cgpa) {
        this->cgpa = cgpa;
    }

    int getroll() {
        return roll;
    }

    float getcg() {
        return cgpa;
    }

    string getname() {
        return name;
    }
};

int main() {
    Student s1;
    Student s2("Karim");
    Student s3(3);
    Student s4(4, "Rahim", 3.52);
    Student s5(5, "Sakib", 3.92);

    s1.setname("Papon");
    s1.setroll(1);
    s1.setcg(4.00);

    s2.setroll(2);
    s2.setcg(3.8);

    s3.setname("Abdul");
    s3.setcg(3.96);

    float avg = (s1.getcg() + s2.getcg() + s3.getcg() + s4.getcg() + s5.getcg()) / 5;

    cout << "Student #1" << endl;
    cout << "Roll : " << s1.getroll() << endl;
    cout << "Name : " << s1.getname() << endl;
    cout << "CGPA : " << s1.getcg() << endl << endl;

    cout << "Student #2" << endl;
    cout << "Roll : " << s2.getroll() << endl;
    cout << "Name : " << s2.getname() << endl;
    cout << "CGPA : " << s2.getcg() << endl << endl;

    cout << "Student #3" << endl;
    cout << "Roll : " << s3.getroll() << endl;
    cout << "Name : " << s3.getname() << endl;
    cout << "CGPA : " << s3.getcg() << endl << endl;

    cout << "Student #4" << endl;
    cout << "Roll : " << s4.getroll() << endl;
    cout << "Name : " << s4.getname() << endl;
    cout << "CGPA : " << s4.getcg() << endl << endl;

    cout << "Student #5" << endl;
    cout << "Roll : " << s5.getroll() << endl;
    cout << "Name : " << s5.getname() << endl;
    cout << "CGPA : " << s5.getcg() << endl << endl;

    cout << "Average of CGPA : " << avg << endl;
    return 0;
}
