#include<iostream>
#include<algorithm>
using namespace std;

int Partition(int A[],int low,int high){
    int pivot = A[low];
    int i=low;
    int j =high+1;
    do{
        do{
            i++;
        }while(A[i]<pivot);
        do{
            j--;
        }while(A[j]>pivot);
        if(i<j){
            swap(A[i],A[j]);
        }
    } while(i<j);
    swap(A[low], A[j]);
    return j;
}

void QuickSort(int A[], int low,int high){
    if(low<high){
        int j=Partition(A,low,high);
        QuickSort(A,low,j-1);
        QuickSort(A,j+1,high);
    }
}

int main(){
    int A[10]= {2,5,1,7,9,10,27,19,19};
    A[9]=INT32_MAX;
    QuickSort(A,0,8);
    for(int i=0;i<9;i++){
        cout<<A[i]<<endl;
    }
   return 0;
}