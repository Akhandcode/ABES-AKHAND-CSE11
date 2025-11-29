#include<iostream>
#include<stdlib.h>
#include <algorithm>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

node* MakeNode(int x) {
    node *p;
    p = (node*) malloc(sizeof(node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void PreOrder(node *T){
    if (T != NULL) {
        cout << T->data << ", ";
        PreOrder(T->left);
        PreOrder(T->right);
    }
}

void InOrder(node *T){
    if (T != NULL) {
        InOrder(T->left);
        cout << T->data << ", ";
        InOrder(T->right);
    }
}

void PostOrder(node *T){
    if (T != NULL) {
        PostOrder(T->left);
        PostOrder(T->right);
        cout << T->data << ", ";
    }
}
int countNode(node*T)
{
    if(T==NULL)
    {
        return 0;
    }
    else
    {
        return 1+countNode(T->left)+countNode(T->right);
    }
}
int countLeafNode(node*T)
{
    if(T==NULL)
    {
        return 0;
    }
    else if(T->left==NULL&&T->right==NULL)
    {
        return 1;
    }
    else
    {
        return countNode(T->left)+countNode(T->right);
    }
}
int CN2(node*T)
{
    if(T==NULL)
    {
        return 0;
    }
    else if(T->left==NULL&&T->right==NULL)
    {
        return 0;
    }
    else if(T->left!=NULL&&T->right!=NULL)
    {
        return CN2(T->left)+CN2(T->right);
    }
    else
    {
        return 1+CN2(T->left)+CN2(T->right);
    }
}
int HeightT(node*T)
{
    if(T==NULL)
    {
        return 0;
    }
    else if(T->left==NULL&&T->right==NULL)
    {
        return 0;
    }
    else
    {
        return 1+max(HeightT(T->left),HeightT(T->right));
    }
}
bool isStrictlyBinary(node *T)
{
    if (T == NULL) 
    {
        return true;  
    }                
    else if ((T->left == NULL && T->right != NULL) || (T->left != NULL && T->right == NULL))
    {
       return false;
    }
    else
    {
    return isStrictlyBinary(T->left) && isStrictlyBinary(T->right);
    }
}
bool isCompleteBinary(node *T)
{
    if (T == NULL) 
    {
        return true;  
    }                
    else if ((T->left == NULL && T->right != NULL) || (T->left != NULL && T->right == NULL))
    {
       return false;
    }
    else
    {
    return isCompleteBinary(T->left) && isCompleteBinary(T->right);
    }
}

void createNode(node **T){
    int choice;
    cout<<"Wheather the left of "<<(*T)->data<<" Exists?(0/1): ";
    cin>>choice;
    if(choice==1){
        int x;
        cout<<"Enter the left child: "<<(*T)->data<<": ";
        cin>>x;
        node *p=MakeNode(x);
        (*T)->left=p;
        createNode(&p);
    }
    cout<<"Wheather the right of "<<(*T)->data<<" Exists?(0/1):  ";
    cin>>choice;
    if(choice==1){
        int x;
        cout<<"Enter the right child "<<(*T)->data<<": ";
        cin>>x;
        node *p=MakeNode(x);
        (*T)->right=p;
        createNode(&p);
    }
}
int main() {
    node *T;
    int x;
    cout<<"Enter the data of root node: ";
    cin>>x;
    T = MakeNode(x);
    createNode(&T);

    cout << "PreOrder Traversal: ";
    PreOrder(T);
    cout << "\nInOrder Traversal: ";
    InOrder(T);
    cout << "\nPostOrder Traversal: ";
    PostOrder(T);
    int m=countNode(T);
    cout <<endl;
    cout<<"Total node are:"<<m;
    int n=countLeafNode(T);
    cout<<endl;
    cout<<"Total Leaf node are:"<<n;
    int z=CN2(T);
    cout<<endl;
    cout<<"Total N2 node are:"<<x;
    int y=HeightT(T);
    cout<<endl;
    cout<<"Total Height of the tree :"<<y;
    cout<<endl;
    cout<<isStrictlyBinary(T);
   return 0;
}

