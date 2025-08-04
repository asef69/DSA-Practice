#include<bits/stdc++.h>
using namespace std;
class base
{
    int x,y;
public:
    base(int n,int p)
    {
        x=n;
        y=p;
        cout<<"Constructing Base class"<<endl;
    }
    ~base()
    {
        cout<<"Destructing base class"<<endl;
    }
    void showxy()
    {
        cout<<x<<" "<<y<<endl;
    }
};
class derived:public base
{
    int i,j;
public:
    derived(int n,int m,int p):base(n,p)
    {
        i=n;
        j=m;
        cout<<"Constructing derived class"<<endl;
    }
    ~derived()
    {
        cout<<"Destructing derived class"<<endl;
    }
    void showij()
    {
        cout<<i<<" "<<j<<endl;
    }
};
int main()
{
    derived ob(10,20,30);
    ob.showxy();
    ob.showij();
    return 0;
}
