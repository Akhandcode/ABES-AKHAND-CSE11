#include<iostream>
using namespace std;
int digit(int k)
{
    int c=0;
    while(k>0)
    {
        k=k/10;
        c++;
    }
    return c;
}
int power(int a,int x)
{
    int pow=1;
    for(int i=0;i<x;i++)
    {
        pow=pow*a;
    }
    return pow;
}
int midSquarhash(int k,int size)
{
    int y;
    int m=digit(size-1);
    int a=power(10,m);
    y=k*k;
    int n=digit(k);
    int x=(2*n-m)/2;
    int d=power(10,x);
    y=y/d;
    int l=y%a;
    return l;
}
int main()
{
    cout<<midSquarhash(1692,100);
}