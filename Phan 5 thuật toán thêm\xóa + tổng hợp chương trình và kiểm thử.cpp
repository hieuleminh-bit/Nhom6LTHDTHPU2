 void boSungNhanVien() {
        if (dsNV.size() >= 199) {
            cout << "Danh sach da dat gioi han toi da (200 nhan vien)!\n";
            return;
        }
        int pos;
        cout << "\nNhap vi tri can chen (0 den " << dsNV.size() << "): ";
        cin >> pos;

        if (pos < 0 || pos > static_cast<int>(dsNV.size())) {
            cout << "Vi tri chen khong hop le!\n";
            return;
        }

        NhanVien nvMoi;
        cout << "\n--- Nhap thong tin nhan vien moi ---\n";
        nvMoi.nhap();

        dsNV.insert(dsNV.begin() + pos, nvMoi);
        cout << "Da them nhan vien vao vi tri " << pos << " thanh cong!\n";
    }

    void xoaNhanVien() {
        if (dsNV.empty()) {
            cout << "Danh sach rong, khong thiet lap xoa!\n";
            return;
        }
        int pos;
        cout << "\nNhap vi tri can xoa (0 den " << dsNV.size() - 1 << "): ";
        cin >> pos;

        if (pos < 0 || pos >= static_cast<int>(dsNV.size())) {
            cout << "Vi tri xoa khong hop le!\n";
            return;
        }

        dsNV.erase(dsNV.begin() + pos);
        cout << "Da xoa nhan vien tai vi tri " << pos << " thanh cong!\n";
    }
};

void hienThiMenu() {
    cout << "\n================= CHUONG TRINH QUAN LY NHAN VIEN =================\n";
    cout << "1. Nhap danh sach nhan vien\n";
    cout << "2. In danh sach nhan vien\n";
    cout << "3. Sap xep danh sach theo luong thuc linh giam dan\n";
    cout << "4. Tim kiem nhan vien theo ma\n";
    cout << "5. Bo sung 1 nhan vien vao vi tri bat ky\n";
    cout << "6. Xoa 1 nhan vien tai vi tri bat ky\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "==================================================================\n";
    cout << "Chon thao tac (0-6): ";
}

int main() {
    QuanLyNhanVien qlnv;
    int luaChon;

    do {
        hienThiMenu();
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                qlnv.nhapDanhSach();
                break;
            case 2:
                qlnv.inDanhSach();
                break;
            case 3:
                qlnv.sapXepGiamDanTheoLuong();
                qlnv.inDanhSach();
                break;
            case 4:
                qlnv.timKiemTheoMa();
                break;
            case 5:
                qlnv.boSungNhanVien();
                break;
            case 6:
                qlnv.xoaNhanVien();
                break;
            case 0:
                cout << "Da thoat chuong trinh. Cam on ban!\n";
                break;
            default:
                cout << "Lua chon khong hop le! Vui long chon lai.\n";
        }
    } while (luaChon != 0);

    return 0;
}
