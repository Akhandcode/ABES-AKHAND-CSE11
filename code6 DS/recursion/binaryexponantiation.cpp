#include<iostream>
using namespace std;

int exponentiationBin(int a,int n)
{
    if(n=0)
    {
        return 1;
    }
    else{
        int x=exponentiationBin(a,n/2);
        if(n%2==0)
            return x*x;
        else
            return a*x*x; 
    }   
}
int main()
{

    int n;
    cout<<"Enter the number for the factor";
    cin>>n;
    int a;
    cout<<"Enter the number for the factor";
    cin>>a;
    cout<<exponentiationBin(n,a);
}