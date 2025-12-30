#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


struct List {
    Node* first;
};


void createList(List &L) {
    L.first = NULL;
}


Node* createNode(int x) {
    Node* P = new Node;
    P->data = x;
    P->next = NULL;
    return P;
}


void insertFirst(List &L, Node* P) {
    P->next = L.first;
    L.first = P;
}


void printList(List L) {
    Node* P = L.first;
    while (P != NULL) {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}


void deleteFirst(List &L) {
    if (L.first != NULL) {
        Node* P = L.first;
        L.first = P->next;
        delete P;
    }
}


void deleteLast(List &L) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            deleteFirst(L);
        } else {
            Node* P = L.first;
            while (P->next->next != NULL) {
                P = P->next;
            }
            delete P->next;
            P->next = NULL;
        }
    }
}


int countNode(List L) {
    int jumlah = 0;
    Node* P = L.first;
    while (P != NULL) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}


void deleteAll(List &L) {
    while (L.first != NULL) {
        deleteFirst(L);
    }
}

int main() {
    List L;
    createList(L);

    insertFirst(L, createNode(2));
    insertFirst(L, createNode(0));
    insertFirst(L, createNode(8));
    insertFirst(L, createNode(12));
    insertFirst(L, createNode(9));

    cout << "Isi List Awal : ";
    printList(L);

    deleteFirst(L);
    cout << "Setelah deleteFirst : ";
    printList(L);

    deleteLast(L);
    cout << "Setelah deleteLast : ";
    printList(L);

    cout << "Jumlah node : " << countNode(L) << endl;

    deleteAll(L);
    cout << "Setelah deleteAll : ";
    printList(L);

    cout << "Jumlah node : " << countNode(L) << endl;

    return 0;
}
