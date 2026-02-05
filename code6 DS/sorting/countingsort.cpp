#include<iostream>
#include<vector>
using namespace std;
vector<int>countsort(vector<int>a,int n,int k)
{
    vector<int>c={0};
    vector<int>b;
    for(int i=0;i<n-1;i++)
    {
        c[a[i]]=c[a[i]]+1;
    }
    for(int i=2;i<k;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    for(int i=n-1;i>0;i--)
    {
        b[c[a[i]]]=a[i];
        c[a[i]]=c[a[i]]-1;
    } 
    return b;   
}
int main()
{

    

}