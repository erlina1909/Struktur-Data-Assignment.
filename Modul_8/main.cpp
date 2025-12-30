#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == 4;
}

// Alternatif 1: head diam, tail bergerak
void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) return;

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) return -1;

    infotype temp = Q.info[Q.head];

    for (int i = 0; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }

    Q.tail--;

    if (Q.tail < 0) {
        Q.head = -1;
        Q.tail = -1;
    }

    return temp;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    CreateQueue(Q);

    cout << "-----------------------" << endl;
    cout << "H - T | Queue Info" << endl;
    cout << "-----------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5);  printInfo(Q);
    enqueue(Q, 2);  printInfo(Q);
    enqueue(Q, 7);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    enqueue(Q, 4);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);

    return 0;
}