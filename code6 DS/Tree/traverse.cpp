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
void PreOrder(node *T){
    if (T != NULL) {
        cout << T->data << ", ";
        PreOrder(T->left);
        PreOrder(T->right);
    }
}
void InOrder(node *T){
    if (T != NULL) {
        PreOrder(T->left);
        cout << T->data << ", ";
        PreOrder(T->right);
    }
}
void PostOrder(node *T){
    if (T != NULL) {
        PreOrder(T->left);
        PreOrder(T->right);
        cout << T->data << ", ";
    }
}
int main()
{
    node *T;
    MakeNode('A');
    T->left=MakeNode('B');
    T->right=MakeNode('C');
    PreOrder(T);

    InOrder(T);

    PostOrder(T);

}
