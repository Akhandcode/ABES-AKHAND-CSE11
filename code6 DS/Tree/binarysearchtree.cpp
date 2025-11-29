#include <iostream>
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
void InOrder(node *T){
    if (T != NULL) {
        InOrder(T->left);
        cout << T->data << ", ";
        InOrder(T->right);
    }
}
node* BSTinsertion(node *T,int x)
{
    node *p=T,*q=NULL;
    while(p!=NULL)
    {
        q=p;
        if(x<p->data)
        {
            p=p->left;
        }
        else{
            p=p->right;
        }
    }
    if(T==NULL)
    {
        T=MakeNode(x);
    }
    else if(x< q->data)
    {
        q->left=MakeNode(x);
    }
    else{
        q->right=MakeNode(x);
    }
}
node *BSTmin(node *T)
{
    while(T->left!=NULL)
    {
        T=T->left;
    }
    return T;
}
node *BSTmax(node *T)
{
    while(T->right!=NULL)
    {
        T=T->right;
    }
    return T;
}
int main()
{
    node *T = NULL;

    // Insert elements into BST
    T = BSTinsertion(T, 50);
    BSTinsertion(T, 30);
    BSTinsertion(T, 70);
    BSTinsertion(T, 20);
    BSTinsertion(T, 40);
    BSTinsertion(T, 60);
    BSTinsertion(T, 80);

    // Inorder traversal (sorted order)
    cout << "Inorder Traversal: ";
    InOrder(T);
    cout << endl;

    // Minimum value
    node *mn = BSTmin(T);
    cout << "Minimum value: " << mn->data << endl;

    // Maximum value
    node *mx = BSTmax(T);
    cout << "Maximum value: " << mx->data << endl;

    return 0;
}