#include <iostream>
using namespace std;

typedef int infotype;

struct ElmList {
    infotype info;
    ElmList* next;
};

struct List {
    ElmList* first;
};


void createList(List &L) {
    L.first = NULL;
}


ElmList* alokasi(infotype x) {
    ElmList* P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}


void dealokasi(ElmList* &P) {
    delete P;
    P = NULL;
}


void insertFirst(List &L, ElmList* P) {
    P->next = L.first;
    L.first = P;
}


void printInfo(List L) {
    ElmList* P = L.first;
    while(P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}


ElmList* findElm(List L, infotype x) {
    ElmList* P = L.first;
    while(P != NULL) {
        if(P->info == x)
            return P;
        P = P->next;
    }
    return NULL;
}


int totalInfo(List L) {
    ElmList* P = L.first;
    int total = 0;
    while(P != NULL) {
        total += P->info;
        P = P->next;
    }
    return total;
}

int main() {
    List L;
    ElmList *P1, *P2, *P3, *P4, *P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "Isi Singly Linked List: ";
    printInfo(L);

    cout << "Pencarian elemen 8: ";
    if(findElm(L, 8) != NULL)
        cout << "Data ditemukan" << endl;
    else
        cout << "Data tidak ditemukan" << endl;

    cout << "Total seluruh info = " << totalInfo(L) << endl;

    return 0;
}
