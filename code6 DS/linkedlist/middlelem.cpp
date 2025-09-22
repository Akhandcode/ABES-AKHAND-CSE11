#include<iostream>
#include<stdlib.h>
#include"linkedlistheader.h"
using namespace std;


Node *MiddleNodeList(Node *Start){
    Node *t=Start;
    Node *r=Start->Next;
    while(r!=NULL && r->Next!=NULL){
        t=t->Next;
        r=r->Next->Next;
    }
    return t;
}

 Node *MiddleNode(Node *Start){
    int c=countNode();
    int i=1;
    Node *p=Start;
    for(i=1;i<(c/2);i++){
        p=p->Next;
    }
    return p;
}


int main() {
    Start = NULL;   // initially list empty
    InsBeg('A');
    InsBeg('B');
    InsBeg('C');
    InsEnd('D');
    InsEnd('E');

    Traverse();

    cout << "Linked List: ";
    cout<<MiddleNode(Start)->info;
    
    return 0;
}
