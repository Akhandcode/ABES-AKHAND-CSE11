#include<iostream>
#include<stdlib.h>
#include"linkedlistheader.h"
using namespace std;


int countNode()
{
    node *p = Start;
    int count=0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

int main() {
    Start = NULL;   // initially list empty
    int count=0;
    InsBeg('A');
    InsBeg('B');  
    InsBeg('C');
    InsEnd('A');
    InsEnd('B');
    InsEnd('C');
    InsEnd('A');
    InsEnd('B');

    Traverse();

    cout << "Linked List: ";
    count=countNode();
    cout<<count;
    return 0;
}
