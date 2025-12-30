#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Input: ";
    cin >> x;

    for(int i = x; i >= 1; i--){
        for(int j = i; j >= 1; j--) cout << j << " ";
        for(int j = 1; j <= i; j++) cout << j << " ";
        cout << endl;
    }
    
    cout << "*" << endl;

    return 0;
}
