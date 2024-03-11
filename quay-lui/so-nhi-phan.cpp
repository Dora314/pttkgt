#include <iostream>
using namespace std;

int n, a[100];

void Print() {
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << endl;
}

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n) {
            Print();
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    cout << "Nhap n? ";
    cin >> n;
    cout << "Kha nang cua so nhi phan: " << endl;
    Try(1);
    return 0;
}