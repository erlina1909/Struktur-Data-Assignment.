#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int A[3][3], int B[3][3], int x, int y) {
    int temp = A[x][y];
    A[x][y] = B[x][y];
    B[x][y] = temp;
}

void tukarPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3] = {{9,8,7},{6,5,4},{3,2,1}};

    cout << "Array A:\n";
    tampilArray(A);

    cout << "\nArray B:\n";
    tampilArray(B);

    tukarArray(A, B, 1, 1);

    cout << "\nSetelah ditukar posisi [1][1]:\n";
    cout << "Array A:\n";
    tampilArray(A);

    cout << "Array B:\n";
    tampilArray(B);

    int x = 10, y = 20;
    tukarPointer(&x, &y);

    cout << "\nSetelah tukar pointer:";
    cout << "\nx = " << x << ", y = " << y << endl;

    return 0;
}
