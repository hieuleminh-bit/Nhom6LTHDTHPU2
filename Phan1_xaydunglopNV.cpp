#include <iostream>
#include <string>
using namespace std;

class NhanVien {
private:
    string maNV;
    string hoTen;
    string phongBan;
    double heSoLuong;
    int soNgayCong;
    double luongThucLinh;

public:
    NhanVien() {
        maNV = "";
        hoTen = "";
        phongBan = "";
        heSoLuong = 0;
        soNgayCong = 0;
        luongThucLinh = 0;
    }

    void tinhLuong() {
        luongThucLinh = heSoLuong * 1800000 / 26 * soNgayCong;
    }
    void nhap() {
        cout << "Nhap ma nhan vien: ";
        getline(cin, maNV);

        cout << "Nhap ho ten: ";
        getline(cin, hoTen);

        cout << "Nhap phong ban: ";
        getline(cin, phongBan);

        cout << "Nhap he so luong: ";
        cin >> heSoLuong;

        cout << "Nhap so ngay cong: ";
        cin >> soNgayCong;

        cin.ignore();

        tinhLuong();
    }

    void xuat() {
        cout << maNV << "\t"
             << hoTen << "\t"
             << phongBan << "\t"
             << heSoLuong << "\t"
             << soNgayCong << "\t"
             << luongThucLinh << endl;
    }

    string getMaNV() {
        return maNV;
    }

    double getLuongThucLinh() {
        return luongThucLinh;
    }
};
