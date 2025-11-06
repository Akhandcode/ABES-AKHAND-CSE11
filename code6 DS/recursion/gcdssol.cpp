#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b); 
}
int main()
{
    int a;
    cout<<"Enter the number";
    cin>>a;
    int b;
    cout<<"Enter the number";
    cin>>b;
    cout<<gcd(a,b);
}