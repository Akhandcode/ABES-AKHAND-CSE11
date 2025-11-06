#include<iostream>
#include<stdlib.h>
#include"linkedlistheader.h"
using namespace std;

void Reverse() {
    node* P = NULL; 
    node* C = Start; 
    node* N = NULL;    

    if (Start == NULL) { 
        return;
    }

    
    while (C != NULL) {
        N = C->next;    
        C->next = P;    
        P = C;          
        C = N;          
    }
    Start = P; // Update the Start pointer to the new head (which is P)
}

int main() {
    InsEnd('A');
    InsEnd('B');
    InsEnd('C');
    InsEnd('D');
    InsEnd('E');

    cout << "Original list: ";
    Traverse();

    Reverse();

    cout << "Reversed list: ";
    Traverse(); 

    return 0;
}
