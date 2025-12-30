#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define MAX 20

struct Stack {
    int info[MAX];
    int top;
};

void createStack(Stack &S) {
    S.top = -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

void push(Stack &S, int x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!\n";
    }
}

int pop(Stack &S) {
    if (!isEmpty(S)) {
        int x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong!\n";
        return -1;
    }
}

void printStack(Stack S) {
    cout << "balik stack\n";
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}


void pushAscending(Stack &S, int x) {
    if (isFull(S)) {
        cout << "Stack penuh!\n";
        return;
    }

    Stack temp;
    createStack(temp);

    
    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    
    push(S, x);

    
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}


void getInputStream(Stack &S) {
    string input;
    cout << "Masukkan angka (pisahkan spasi, tekan ENTER untuk selesai):\n";

    getline(cin, input);
    stringstream ss(input);

    int x;
    while (ss >> x) {
        push(S, x);
    }
}


int main() {
    Stack S;
    createStack(S);

    cout << "=== Demo Stack ===\n";

    push(S, 9);
    push(S, 8);
    push(S, 4);
    push(S, 3);
    push(S, 2);

    cout << "Stack awal:\n";
    printStack(S);

    cout << "\nPush ascending 5...\n";
    pushAscending(S, 5);
    printStack(S);

    cout << "\nInput stream ke stack...\n";
    createStack(S);    
    getInputStream(S);
    printStack(S);

    return 0;
}
