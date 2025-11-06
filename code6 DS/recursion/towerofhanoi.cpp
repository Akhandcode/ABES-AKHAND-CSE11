#include<iostream>
using namespace std;
int towerOfhanoi(int n,char s,char m,char d)
{
    if(n==1)
    {
        cout<<s<<"-->"<<d;
        cout<<endl;
    }
    else
    {
        towerOfhanoi(n-1,s,d,m);
        cout<<s<<"-->"<<d;
        cout<<endl;
        towerOfhanoi(n-1,m,s,d);
    }

}
int main()
{
    int n;
    cout<<"Enter the number";
    cin>>n;
    towerOfhanoi(n,'s','m','d');
}