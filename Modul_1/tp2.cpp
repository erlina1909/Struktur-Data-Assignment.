#include <iostream>
#include <string>
using namespace std;

string satuan[] = {"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan"};
string belasan[] = {"sepuluh","sebelas","dua belas","tiga belas","empat belas","lima belas",
                    "enam belas","tujuh belas","delapan belas","sembilan belas"};
string puluhan[] = {"","", "dua puluh","tiga puluh","empat puluh","lima puluh",
                    "enam puluh","tujuh puluh","delapan puluh","sembilan puluh"};

string terbilang(int n){
    if(n < 10) return satuan[n];
    else if(n < 20) return belasan[n - 10];
    else {
        int p = n / 10;
        int s = n % 10;
        if(s == 0) return puluhan[p];
        else return puluhan[p] + " " + satuan[s];
    }
}

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    if(n == 100)
        cout << "seratus" << endl;
    else
        cout << terbilang(n) << endl;

    return 0;
}
