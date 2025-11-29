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

void RandQS(int A[], int low,int high){
    if(low<high){
        int j=Partition(A,low,high);
        RandQS(A,low,j-1);
        RandQS(A,j+1,high);
    }
}