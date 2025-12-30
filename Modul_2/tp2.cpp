#include <iostream>
using namespace std;

void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x, y, z;

    cout << "Masukkan nilai x y z: ";
    cin >> x >> y >> z;

    tukarPointer(&x, &y, &z);
    cout << "\nSetelah ditukar (Pointer): ";
    cout << x << " " << y << " " << z << endl;

    tukarReference(x, y, z);
    cout << "Setelah ditukar (Reference): ";
    cout << x << " " << y << " " << z << endl;

    return 0;
}
