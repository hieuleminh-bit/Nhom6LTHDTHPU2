#include <iostream>
#include <string>
using namespace std;

class NhanVien {
private:
    string maNV;
    string hoTen;
    double heSoLuong;
    int soNgayCong;

public:
    void nhap() {
        cout << "Ma nhan vien: ";
        cin >> maNV;

        cin.ignore();
        cout << "Ho ten: ";
        getline(cin, hoTen);

        cout << "He so luong: ";
        cin >> heSoLuong;

        cout << "So ngay cong: ";
        cin >> soNgayCong;
    }

    double getLuong() const {
        return heSoLuong * 1800000 / 26 * soNgayCong;
    }

    void xuat() const {
        cout << maNV << " - "
             << hoTen << " - Luong: "
             << getLuong() << endl;
    }
};

class QuanLyNhanVien {
private:
    NhanVien ds[200];
    int n;

public:
    void nhapDanhSach() {
        cout << "Nhap so luong nhan vien: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "\nNhan vien thu " << i + 1 << ":\n";
            ds[i].nhap();
        }
    }

    // PHẦN 3: SẮP XẾP THEO LƯƠNG GIẢM DẦN
    void sapXepLuongGiamDan() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (ds[i].getLuong() < ds[j].getLuong()) {
                    swap(ds[i], ds[j]);
                }
            }
        }
    }

    void xuatDanhSach() const {
        for (int i = 0; i < n; i++) {
            ds[i].xuat();
        }
    }
};

int main() {
    QuanLyNhanVien ql;

    ql.nhapDanhSach();

    cout << "\nDanh sach truoc khi sap xep:\n";
    ql.xuatDanhSach();

    ql.sapXepLuongGiamDan();

    cout << "\nDanh sach sau khi sap xep luong giam dan:\n";
    ql.xuatDanhSach();

    return 0;
}
