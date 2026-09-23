#include <iostream>
using namespace std;

class M1C {
private:
    int spt;
    int a[200];

public:
    void nhap();
    void xuat();
};

 void M1C::nhap() {
    cout << "So phan tu: ";
    cin >> spt;

    for (int i = 0; i < spt; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void M1C::xuat() {
    for (int i = 0; i < spt; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    M1C m;
    int x, k;

    m.nhap();

    cout << "Mang: ";
    m.xuat();
    return 0;
}
