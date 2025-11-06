#include<iostream>
using namespace std;

int arrSum(int a[10],int n)
{
    if(n==0)
    {
        return a[0];
    }
    else 
      return a[n]+arrSum(a,n-1);
}
int main()
{
    int n;
    cout<<"Enter the number";
    cin>>n;
    int a[10];
    cout<<"Enter the elements in the array";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<arrSum(a,n-1);
}