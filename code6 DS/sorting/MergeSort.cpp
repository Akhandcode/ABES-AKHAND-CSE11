#include<iostream>
#include<algorithm>
using namespace std;
int Merge(int a[],int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=low;
    int c[10];
    while ((i<mid)&&(j<=high))
    {
        if(a[i]<a[j])
        {
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            c[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        c[k]=a[j];
        j++;
        k++;
    }
    for(int i=low;i<=high;i++)
    {
        a[i]=c[i];
    } 
}
int MergeSort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        Merge(a,low,mid,high);
    }
}
int main(){
    int a[10]= {2,5,1,7,9,10,27,6,19};
    MergeSort(a,0,8);
    for(int i=0;i<9;i++){
        cout<<a[i]<<endl;
    }
   return 0;
}
