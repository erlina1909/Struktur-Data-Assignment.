#include <iostream>
using namespace std;

struct infotype {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
};

struct elmlist {
    infotype info;
    elmlist *next;
    elmlist *prev;
};

struct List {
    elmlist *first;
};

typedef elmlist* address;


void CreateList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        P->next = P;
        P->prev = P;
    } else {
        address last = L.first->prev;
        P->next = L.first;
        P->prev = last;
        last->next = P;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        insertFirst(L, P);
    } else {
        address last = L.first->prev;
        P->next = L.first;
        P->prev = last;
        last->next = P;
        L.first->prev = P;
    }
}

address findElm(List L, string nim) {
    if (L.first == NULL) return NULL;

    address P = L.first;
    do {
        if (P->info.nim == nim) {
            return P;
        }
        P = P->next;
    } while (P != L.first);

    return NULL;
}

void deleteFirst(List &L, address &P) {
    if (L.first != NULL) {
        P = L.first;
        if (P->next == P) {
            L.first = NULL;
        } else {
            address last = P->prev;
            L.first = P->next;
            last->next = L.first;
            L.first->prev = last;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void printInfo(List L) {
    if (L.first == NULL) {
        cout << "List kosong" << endl;
    } else {
        address P = L.first;
        do {
            cout << P->info.nama << " | "
                 << P->info.nim << " | "
                 << P->info.jenis_kelamin << " | "
                 << P->info.ipk << endl;
            P = P->next;
        } while (P != L.first);
    }
}



infotype createData(string nama, string nim, char jk, float ipk) {
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jk;
    x.ipk = ipk;
    return x;
}

int main() {
    List L;
    CreateList(L);

    address P1 = alokasi(createData("Sean", "001", 'L', 3.4));
    address P2 = alokasi(createData("Lina", "002", 'P', 3.6));
    address P3 = alokasi(createData("Andi", "003", 'L', 3.2));

    insertFirst(L, P1);
    insertLast(L, P2);
    insertLast(L, P3);

    cout << "Data awal:" << endl;
    printInfo(L);

    address cari = findElm(L, "002");
    if (cari != NULL) {
        cout << "\nData ditemukan: " << cari->info.nama << endl;
    }

    address H;
    deleteFirst(L, H);
    dealokasi(H);

    cout << "\nSetelah delete first:" << endl;
    printInfo(L);

    return 0;
}