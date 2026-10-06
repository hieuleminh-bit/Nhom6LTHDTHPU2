#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

#define LUONG_CO_BAN 1800000.0

class NhanVien {
private:
    string maNV;
    string hoTen;
    string phongBan;
    float heSoLuong;
    int soNgayCong;

public:
    NhanVien() : heSoLuong(0.0), soNgayCong(0) {}
    NhanVien(string ma, string ten, string pb, float hs, int nc)
        : maNV(ma), hoTen(ten), phongBan(pb), heSoLuong(hs), soNgayCong(nc) {}

    string getMaNV() const { return maNV; }
    string getHoTen() const { return hoTen; }
    string getPhongBan() const { return phongBan; }
    float getHeSoLuong() const { return heSoLuong; }
    int getSoNgayCong() const { return soNgayCong; }

    double tinhLuongThucLinh() const {
        return (heSoLuong * LUONG_CO_BAN / 22.0) * soNgayCong;
    }

    void nhap() {
        cout << "  - Nhap ma NV: ";
        getline(cin >> ws, maNV);
        cout << "  - Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "  - Nhap phong ban: ";
        getline(cin, phongBan);
        cout << "  - Nhap he so luong: ";
        cin >> heSoLuong;
        cout << "  - Nhap so ngay cong: ";
        cin >> soNgayCong;
    }

    void xuat() const {
        cout << left << setw(12) << maNV
             << setw(25) << hoTen
             << setw(18) << phongBan
             << setw(12) << fixed << setprecision(2) << heSoLuong
             << setw(15) << soNgayCong
             << setw(18) << fixed << setprecision(0) << tinhLuongThucLinh() << "\n";
    }
};

class QuanLyNhanVien {
private:
    vector<NhanVien> dsNV;

public:
    void nhapDanhSach() {
        int n;
        cout << "Nhap so luong nhan vien can them: ";
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cout << "\n--- Nhap nhan vien thu " << i + 1 << " ---\n";
            NhanVien nv;
            nv.nhap();
            dsNV.push_back(nv);
        }
    }

    void hienThiDanhSach() const {
        if (dsNV.empty()) {
            cout << "\nDanh sach rong!\n";
            return;
        }
        cout << "\n================================ DANH SACH NHAN VIEN ================================\n";
        cout << left << setw(12) << "Ma NV"
             << setw(25) << "Ho Ten"
             << setw(18) << "Phong Ban"
             << setw(12) << "HS Luong"
             << setw(15) << "Ngay Cong"
             << setw(18) << "Luong Thuc Linh (VND)" << "\n";
        cout << string(100, '-') << "\n";
        for (const auto& nv : dsNV) {
            nv.xuat();
        }
        cout << string(100, '=') << "\n";
    }

    void timKiemTheoMa() const {
        if (dsNV.empty()) {
            cout << "Danh sach rong!\n";
            return;
        }
        string maTim;
        cout << "\nNhap ma nhan vien can tim: ";
        // Đã sửa: dùng `cin >> ws` để xóa khoảng trắng/xuống dòng dư thừa an toàn hơn cin.ignore()
        getline(cin >> ws, maTim);

        bool timThay = false;
        for (const auto& nv : dsNV) {
            if (nv.getMaNV() == maTim) {
                cout << "\n--- Thong tin nhan vien tim thay ---\n";
                cout << left << setw(12) << "Ma NV"
                     << setw(25) << "Ho Ten"
                     << setw(18) << "Phong Ban"
                     << setw(12) << "HS Luong"
                     << setw(15) << "Ngay Cong"
                     << setw(18) << "Luong Thuc Linh (VND)" << "\n";
                cout << string(100, '-') << "\n";
                nv.xuat();
                timThay = true;
                break;
            }
        }
        if (!timThay) {
            cout << "Khong tim thay nhan vien co ma: " << maTim << "\n";
        }
    }
};

int main() {
    QuanLyNhanVien ql;
    int chon;
    
    // Đã sửa: Thêm cặp ngoặc nhọn { } cho khối do-while
    do {
        cout << "1. Nhap danh sach nhan vien\n";
        cout << "2. Hien thi danh sach nhan vien\n";
        cout << "3. Tim kiem nhan vien theo ma\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> chon;

        switch (chon) {
            case 1:
                ql.nhapDanhSach();
                break;
            case 2:
                ql.hienThiDanhSach();
                break;
            case 3:
                ql.timKiemTheoMa();
                break;
            case 0:
                cout << "Da thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le, vui long chon lai!\n";
        }
    } while (chon != 0);

    return 0;
}
