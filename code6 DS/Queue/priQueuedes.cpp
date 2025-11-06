#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void traverseArray(vector<int> &X){
    for(int i=0;i<X.size();i++){
        cout<<X[i]<<" ";
    }
    cout << endl;
}

void arraysortInsertion(vector<int>& A, int i,int x,int n){
    A.insert(A.begin() + i, x);
}

void arrayDeletion(vector<int>&A, int pos,int n){
    for(int i=pos-1;i<A.size()-1;i++){
        A[i]=A[i+1];
    }
    A.pop_back();
}

int deQueue(vector<int>& A,int n)
{
    int x=A.back();   
    A.pop_back();
    return x;
}

void enQueue(vector<int>&A,int n,int x)
{
    int i=0;
   
    while(i < A.size() && x <= A[i])
    {
        i++;
    }
    arraysortInsertion(A, i, x, n);
}

int main()
{
    int n,x,pos;
    cout<<"Enter the size of array: ";
    cin >>n;
    cout<<"Enter elements of array: ";
    vector<int> A;
    for(int i=0;i<n;i++){
       int t;
       cin>>t;
       A.push_back(t);
    }
    sort(A.begin(),A.end(),greater<int>());

    cout<<"Enter the element to insert in queue: ";
    cin>>x;
    enQueue(A,n,x);
    cout<<"After insertion: ";
    traverseArray(A);

    cout<<"Enter the position where the element is deleted: ";
    cin>>pos;
    if(pos<1 || pos>A.size()){
        cout<<"Invalid position." <<endl;
        return 0;
    }
    arrayDeletion(A,pos,n);
    cout<<"After deletion: ";
    traverseArray(A);
    cout << "Dequeued element: " << deQueue(A,n) << endl;
    cout << "Queue after dequeue: ";
    traverseArray(A);

    return 0;
}
