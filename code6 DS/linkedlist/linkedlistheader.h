#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node {
    char info;
    struct Node *Next;
};

struct Node *Start;   

Node *GetNode() {
    Node *p;
    p = (Node*)malloc(sizeof(struct Node));
    return p;
}


void InsBeg(char x) {
    Node *p = GetNode();
    p->info = x;
    p->Next = Start;
    Start = p;
}

void InsEnd(char x) {
    Node *p = GetNode();
    p->info = x;
    p->Next = NULL;

    if (Start == NULL) {   
        Start = p;
        return;
    }
    Node *q = Start;
    while (q->Next != NULL) {
        q = q->Next;
    }
    q->Next = p;
}

void Traverse() {
    Node *p = Start;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->Next;
    }
    cout << endl;
}
int countNode()
{
    Node *p = Start;
    int count=0;
    while (p != NULL) {
        count++;
        p = p->Next;
    }
    return count;
}
