#include <iostream>
using namespace std;
struct node {
    int data;
    struct node *left;
    struct node *right;
    struct  node *parent;
};
node* MakeNode(int x) {
    node *p;
    p = (node*) malloc(sizeof(node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    p->parent = NULL;
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
    node* newNode = MakeNode(x);
    if(T==NULL)
    {
        T=newNode;
    }
    else if(x< q->data)
    {
        q->left=newNode;
        newNode->parent = q;
    }
    else{
        q->right=newNode;
        newNode->parent = q;
    }
    return T;
}
node *BSTmin(node *T)
{
    while(T->left!=NULL)
    {
        T=T->left;
    }
    return T;
}
void freenode(node* p) {
    delete p;
}
node* BSTsuccessor(node* p) {
    node* q = p->parent;
    if (p->right != NULL) {
        return BSTmin(p->right);
    }
       while (q != NULL && p == q->right) {
        p = q;
        q = q->parent;
}

    return q;  
}
node *BSTmax(node *T)
{
    while(T->right!=NULL)
    {
        T=T->right;
    }
    return T;
}
node* BSTpredecessor(node* p) {
    node* q = p->parent;
    if (p->left != NULL) {
        return BSTmax(p->left);
    }
       while (q != NULL && p == q->left) {
        p = q;
        q = q->parent;
}

    return q;  
}
bool isLeft(node* p) {
    if (p->parent->left == p)
        return true;
    else
        return false;
}
bool isRight(node* p) {
    if (p->parent->right == p)
        return true;
    else
        return false;
}
node* BSTDeletion(node* p) {
    node* q;
    node* r;
    int x;

    if (p == NULL) return NULL;

    // ---------- CASE 1 :----------
    int y=p->data;
    if (p->left == NULL && p->right == NULL) {
        if (isLeft(p))
            p->parent->left = NULL;
        else
            p->parent->right = NULL;

        freenode(p);
    }

    // ---------- CASE 2 :----------
    else if ( (p->left == NULL) ||(p->right == NULL) ) {
        if (p->left == NULL)
            q = p->right;
        else 
            q = p->left;

        r = p->parent;
        if (isLeft(p))
            p->parent->left = q;
        else if (isRight(p))
            p->parent->right = q;

        q->parent=r;
        freenode(p);
    }

    // ---------- CASE 3 :----------
    else {
        q=BSTsuccessor(p);  
        p->data=x;
        p=q;      
    }
    freenode(p);
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
    cout << "Inorder Traversal: ";
    InOrder(T);
    cout << endl;
    node *mn = BSTmin(T);
    cout << "Minimum value: " << mn->data << endl;
    node *mx = BSTmax(T);
    cout << "Maximum value: " << mx->data << endl;
    cout << "Successor of 60: ";
    node* s = BSTsuccessor(T->right->left); 
    cout << s->data << endl;
    cout << "Successor of 70: ";
    node* s70 = BSTsuccessor(T->right); 
    cout << s70->data << endl;
    cout << "\nDeleting 20 (leaf node)..." << endl;
    BSTDeletion(T->left->left);
    cout << "Inorder after deleting 20: ";
    InOrder(T);
    cout << endl;

    return 0;
}