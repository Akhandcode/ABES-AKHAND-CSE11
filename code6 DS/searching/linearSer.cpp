#include<iostream>
using namespace std;
        int linearSirch(int arr[10],int key)
        {
            for(int i=0;i<10;i++)
            {
                if(arr[i]==key)
                {
                    return i;
                }
            }
            return -1;
        }
        int main()
        {
            int n;
            cout<<"enter the number of elements";
            cin>>n;
            int arr[10];
            cout<<"Enter the elements in the array";
            for(int i=0;i<n;i++)
            {
                cin>>arr[i];
            }
            int key;
            cout<<"Enter element to be found";
            cin>>key;
            int x=linearSirch(arr,key);
            cout<<x;
        }