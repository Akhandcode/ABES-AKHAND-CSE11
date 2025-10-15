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
    if (q != NULL)
        q->next = NULL;
    else
        Start = NULL; // List had only one element
    char x = p->data;
    FreeNode(p);
    return x;
}

char delAfter(node* Q) {
    if (Q == NULL || Q->next == NULL) return '\0'; // nothing to delete
    node* p = Q->next;
    node* R = p->next;
    Q->next = R;
    char x = p->data;
    FreeNode(p);
    return x;
}

int main() {
    // Insert at beginning
    InsBeg('C');
    InsBeg('B');
    InsBeg('A');
    cout << "After inserting A, B, C at beginning: ";
    Traverse();

    // Insert at end
    InsEnd('D');
    InsEnd('E');
    cout << "After inserting D, E at end: ";
    Traverse();

    // Insert after second node
    insAfter(Start->next, 'X'); // After 'B'
    cout << "After inserting X after B: ";
    Traverse();

    // Delete from beginning
    char del1 = delBeg();
    cout << "Deleted from beginning: " << del1 << endl;
    Traverse();

    // Delete from end
    char del2 = delEnd();
    cout << "Deleted from end: " << del2 << endl;
    Traverse();

    // Delete after first node
    char del3 = delAfter(Start); // after 'B'
    cout << "Deleted after first node: " << del3 << endl;
    Traverse();

    return 0;
}
