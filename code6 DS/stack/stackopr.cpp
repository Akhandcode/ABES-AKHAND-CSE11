#include<iostream>
#define STACKSIZE 10
using namespace std;

struct stack {
    int item[STACKSIZE];
    int top;
} S;

void Initialize() {
    S.top = -1;
}

bool IsEmpty() {
    return (S.top == -1);
}

int push(int x) {
    if (S.top == STACKSIZE - 1) {
        cout << "Stack overflow\n";
        exit(1);
    } else {
        S.top += 1;
        S.item[S.top] = x;
    }
    return x;
}

int pop() {
    if (IsEmpty()) {
        cout << "Stack underflow\n";
        exit(1);
    } else {
        int x = S.item[S.top];
        S.top -= 1;
        return x;
    }
}

int stackTop() {
    if (IsEmpty()) {
        cout << "Stack is empty\n";
        exit(1);
    }
    return S.item[S.top];
}

int main() {
    Initialize();

    // Push elements
    cout << "Pushing elements: 10, 20, 30\n";
    push(10);
    push(20);
    push(30);

    // Show top
    cout << "Current top: " << stackTop() << endl;

    // Pop one element
    cout << "Popped: " << pop() << endl;

    // Show top again
    cout << "Current top after pop: " << stackTop() << endl;

    // Pop remaining
    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl;

    // Try to pop from empty stack (will exit with error)
    // cout << "Popped: " << pop() << endl;

    return 0;
}
