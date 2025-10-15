#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node {
    char info;
    struct Node *Next;
};

struct Node *Start;   // global pointer

char FreeNode(Node* p) {
    free(p);
}

void Traverse() {
    Node* p = Start;
    
    while (p != NULL) {
        cout << p-> info<< " ";
        p = p->Next;
    }
    cout << endl;
}


// New Node allocate karna
Node *GetNode() {
    Node *p;
    p = (Node*)malloc(sizeof(struct Node));
    return p;
}

char delBeg() {
    Node* p = Start;
    Start = Start->Next;
    char x = p->info;
    FreeNode(p);
    return x;
}

int main()
{
     char del1 = delBeg();
    cout << "Deleted from beginning: " << del1 << endl;
    Traverse();
}