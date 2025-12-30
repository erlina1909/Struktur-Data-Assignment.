#include <iostream>
#include <string>
using namespace std;


struct infotype {
    string nopol;
    string warna;
    int thnbuat;
};

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};


void createList(List &L);
address alokasi(infotype x);
void dealokasi(address p);
void insertLast(List &L, address p);
void printInfo(List L);
address findElm(List L, string nopol);
bool deleteElm(List &L, string nopol);


void createList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address p = new ElmList;
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void dealokasi(address p) {
    delete p;
}

address findElm(List L, string nopol) {
    address p = L.First;
    while (p != NULL) {
        if (p->info.nopol == nopol) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void insertLast(List &L, address p) {
    if (L.First == NULL) {
        L.First = p;
        L.Last = p;
    } else {
        L.Last->next = p;
        p->prev = L.Last;
        L.Last = p;
    }
}

bool deleteElm(List &L, string nopol) {
    address p = findElm(L, nopol);
    if (p == NULL) return false;

    if (p == L.First && p == L.Last) {  
        L.First = NULL;
        L.Last = NULL;
    } else if (p == L.First) {          
        L.First = p->next;
        L.First->prev = NULL;
    } else if (p == L.Last) {           
        L.Last = p->prev;
        L.Last->next = NULL;
    } else {                            
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    dealokasi(p);
    return true;
}

void printInfo(List L) {
    address p = L.First;
    cout << "\nDATA LIST :\n";
    while (p != NULL) {
        cout << "no polisi : " << p->info.nopol << endl;
        cout << "warna    : " << p->info.warna << endl;
        cout << "tahun    : " << p->info.thnbuat << endl;
        cout << "----------------------\n";
        p = p->next;
    }
}


int main() {
    List L;
    createList(L);

    infotype x;
    int pil;

    do {
        cout << "\nMENU\n";
        cout << "1. Input data kendaraan\n";
        cout << "2. Cari berdasarkan nopol\n";
        cout << "3. Hapus data berdasarkan nopol\n";
        cout << "4. Tampilkan list\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pil;
        cin.ignore();

        switch (pil) {
        case 1:
            cout << "masukkan nomor polisi: ";
            getline(cin, x.nopol);

            
            if (findElm(L, x.nopol) != NULL) {
                cout << "nomor polisi sudah terdaftar!\n";
                break;
            }

            cout << "masukkan warna kendaraan: ";
            getline(cin, x.warna);

            cout << "masukkan tahun kendaraan: ";
            cin >> x.thnbuat;
            cin.ignore();

            insertLast(L, alokasi(x));
            cout << "data berhasil ditambahkan!\n";
            break;

        case 2: {
            string cari;
            cout << "masukkan nomor polisi: ";
            getline(cin, cari);

            address p = findElm(L, cari);
            if (p != NULL) {
                cout << "DATA DITEMUKAN:\n";
                cout << "nopol : " << p->info.nopol << endl;
                cout << "warna : " << p->info.warna << endl;
                cout << "tahun : " << p->info.thnbuat << endl;
            } else {
                cout << "DATA TIDAK DITEMUKAN\n";
            }
            break;
        }

        case 3: {
            string hapus;
            cout << "masukkan nomor polisi yang dihapus: ";
            getline(cin, hapus);

            if (deleteElm(L, hapus)) {
                cout << "data berhasil dihapus!\n";
            } else {
                cout << "data tidak ditemukan!\n";
            }
            break;
        }

        case 4:
            printInfo(L);
            break;
        }

    } while (pil != 0);

    return 0;
}
