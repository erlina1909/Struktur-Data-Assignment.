#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3];
    int tambah[3][3], kurang[3][3], kali[3][3];

    cout << "Input Matriks A (3x3)\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> A[i][j];
        }
    }

    cout << "\nInput Matriks B (3x3)\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> B[i][j];
        }
    }

    // Penjumlahan & Pengurangan
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tambah[i][j] = A[i][j] + B[i][j];
            kurang[i][j] = A[i][j] - B[i][j];
        }
    }

    // Perkalian
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            kali[i][j] = 0;
            for(int k = 0; k < 3; k++){
                kali[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nHasil Penjumlahan:\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << tambah[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Pengurangan:\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << kurang[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Perkalian:\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << kali[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}