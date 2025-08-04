#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Gen{
T ob;
public:
Gen (T o){
    ob=o;
}
T getObj(){ return ob;}
void showtype();
};
template<class T>
void Gen<T>::showtype(){
    cout<<"Type: "<<typeid(ob).name()<<endl;

}
int main(){
    Gen<int> iob(88);
    iob.showtype();
    cout<<"Value: "<<iob.getObj()<<endl;
    Gen<double> dob(22.22);
    dob.showtype();
    cout<<"Value: "<<dob.getObj()<<endl;
    Gen<string> cob("Template Test");
    cob.showtype();
    cout<<"Value: "<<cob.getObj()<<endl;
    return 0;
}
