#include <iostream>
#include <vector>
using namespace std;

void traverseArray(vector<int> &X){
    for(int i=0;i<X.size();i++){
        cout<<X[i]<<" ";
    }
    cout << endl;
}
void arraysortInsertion(vector<int>& A, int i,int x,int n){
    while(i <= A.size() - 1 && x >= A[i]){
        i++;
    }

    A.insert(A.begin() + i, x);
}
void arrayDeletion(vector<int>&A, int pos,int n){
    int x=A[pos];
    for(int i=pos-1;i<A.size()-1;i++){
        A[i]=A[i+1];
    }
    A.pop_back();
    
}
int deQueue(vector<int>& A,int n)
{
    int x=A[0];
    arrayDeletion(A,0,n);
    return x;

}
int enQueue(vector<int>&A,int n,int x)
{
    int i=0;
    while(i<n&&x>=A[i])
    {
        i=i+1;
    }
    arraysortInsertion(A,i,x,n);
}
int main()
{
    int n,x,pos;
    cout<<"Enter the size of array: ";
    cin >>n;
    cout<<"Enter element of array: ";
    vector<int> A;
    for(int i=0;i<n;i++){
       int t;
       cin>>t;
       A.push_back(t);
    }
    // cout<<"Enter the element to be insert in an array:";
    // cin>>x;
    // enQueue(A,n,x);
    // traverseArray(A);
    cout<<"Enter the position where the element is deleted :";
    cin>>pos;
    if(pos<1 || pos>A.size()){
        cout<<"Invalid position:" <<endl;
        return 0;
    }
    deQueue(A,pos);
    cout<<"After deletion of an array: ";
    traverseArray(A);
    return 0;
}