#include <iostream>
using namespace std;

int n, a[100];
int tongA = 0, tongB = 0, can[100];

void Print() {
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << endl;
}

void CanBangQuaCan() {
    for (int i = 0; i <= n; i++) {
        if (a[i] == 0) {
            tongA += can[i];
        } else {
            tongB += can[i];
        }
    }
    if (tongA == tongB) {
        Print();
    }
    tongA = 0;
    tongB = 0;
}

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n) {
            CanBangQuaCan();
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    cout << "Nhap n? ";
    cin >> n;
    cout << "Nhap so can (cach nhau dau cach)? ";
    for (int i = 1; i <= n; i++) {
        cin >> can[i];
    }
    Try(1);
    return 0;
}