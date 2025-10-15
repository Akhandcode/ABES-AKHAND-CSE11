#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
    char data;
    struct node* next;
};


node* GetNode() {
    node* p = (node*)malloc(sizeof(node));
    return p;
};


void FreeNode(node* p) {
    free(p);
}


struct node* Start = NULL;


void Traverse() {
    node* p = Start;
    
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


void InsBeg(char x) {
    node* p = GetNode();
    p->data = x;
    p->next = Start;
    Start = p;
}


void InsEnd(char x) {
    node* p = GetNode();
    p->data = x;
    p->next = NULL;

    if (Start == NULL) {
        Start = p;
        return;
    }
    
    node* q = Start;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = p;
}


void insAfter(node* q, char x) {
    node* p = GetNode();
    p->data = x;
    node* r = q->next;
    q->next = p;
    p->next = r; 
}


char delBeg() {
    node* p = Start;
    Start = Start->next;
    char x = p->data;
    FreeNode(p);
    return x;
}


char delEnd() {
    node* p = Start;
    node* q = NULL;
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    char x = p->data;
    FreeNode(p);
    return x;
}


char delAfter(node* Q) {
    node* p = Q->next;
    node* R = p->next;
    Q->next = R;
    char x = p->data;
    FreeNode(p);
    return x;
}