#include <iostream>
using namespace std;

int n, m, minimum, a[100], tasksValue[100], tong[100];

void Print() {
    for (int i = 1; i <= m; i++) {
        cout << "Cong nhan " << i << " nhan task thu: ";
    }
    cout << endl;
}

void GiaoTasks() {
    for (int i = 1; i <= m; i++) {
        tong[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        tong[a[i]] += tasksValue[i];
    }
    minimum = tong[1];
    for (int i = 2; i <= m; i++) {
        if (tong[i] < minimum) {
            minimum = tong[i];
        }
    }
    if (minimum == 0) {
        Print();
    }
}

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n) {
            GiaoTasks();
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    cout << "Nhap so task? ";
    cin >> n;
    cout << "Nhap so cong nhan? ";
    cin >> m;
    cout << "Nhap thu lao (cach nhau dau cach)? ";
    for (int i = 1; i <= n; i++) {
        cin >> tasksValue[i];
    }
    Try(1);
    return 0;
}