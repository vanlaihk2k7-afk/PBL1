#include<iostream>
using namespace std;
#include "quanlynhanvien.h"
int main() {
    int chucvu = chonchucvu(); 
    quanlynhanvien qlnv;
    // qlnv.docfile();
    int chon;
    int tiep;
    do {
        cout << "+==========================================================+" << endl;
        cout << "|                  MENU QUAN LY NHAN VIEN                  |" << endl;
        cout << "+====+=====================================================+" << endl;
        cout << "| STT|             CHUC NANG CHUONG TRINH                  |" << endl;
        cout << "+----+-----------------------------------------------------+" << endl;
        if(chucvu == 1) { 
            cout << "| [1]| Nhap danh sach nhan vien ban dau                    |" << endl;
            cout << "| [2]| Xem danh sach nhan vien                             |" << endl;
            cout << "| [3]| Tim kiem nhan vien                                  |" << endl;
            cout << "| [4]| Cap nhat thong tin nhan vien                        |" << endl;
            cout << "| [5]| Them nhan vien                                      |" << endl;
            cout << "| [6]| Xoa thong tin nhan vien                             |" << endl;
            cout << "| [7]| Sap xep nhan vien theo ten nhan vien                |" << endl;
            cout << "| [8]| Lich su dang nhap                                   |" << endl;
            cout << "| [9]| Tinh tong luong phai tra cho toan cong ty           |" << endl;
            cout <<"| [10]| Tong so luong nhan vien trong cong ty               |" << endl;
        } 
        else if(chucvu == 2) { 
            cout << "| [2]| Xem danh sach nhan vien                              |" << endl;
            cout << "| [3]| Tim kiem nhan vien                                   |" << endl;
        }
    
        cout << "| [0]| Thoat chuong trinh                                  |" << endl;
        cout << "+----+-----------------------------------------------------+" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> chon;
        cin.ignore();

        switch(chon) {
            case 1:
                if (chucvu == 1) {
                    qlnv.nhap();
                } else {
                    cout << "Ban khong co quyen dung chuc nang nay!" << endl;
                }
                break;
                
            case 2: 
               qlnv.docfile();
                qlnv.xuat(); 
                break;
            case 3: {
                int manv;
                cout << "Nhap ma nhan vien can tim: ";
                cin >> manv;
                cin.ignore();
                qlnv.timkiemtheomanv(manv);
                break;
            }
            
            case 4:
                if (chucvu == 1) {
                    int manv;
                    cout << "Nhap ma nhan vien can cap nhat: ";
                    cin >> manv;
                    cin.ignore();
                     qlnv.updatenhanvien(manv);
                } else {
                    cout << "[-] Ban khong co quyen dung chuc nang nay!" << endl;
                }
                break;
                
            case 5:
                if (chucvu == 1) {
                    qlnv.addnhanvien();
                } else {
                    cout << " Ban khong co quyen dung chuc nang nay!" << endl;
                }
                break;
            case 6:
                if (chucvu == 1) {
                    int manv;
                    cout << "Nhap ma nhan vien can xoa: ";
                    cin >> manv;
                    cin.ignore();
                    qlnv.deletenhanvien(manv);
                } else {
                    cout << "[-] Ban khong co quyen dung chuc nang nay!" << endl;
                }
                break;
            case 7:
                if (chucvu == 1) {
                    // qlnv.sapxeptheoten();
                } else {
                    cout << "[-] Ban khong co quyen dung chuc nang nay!" << endl;
                }
                break;
            case 8: 
                if (chucvu == 1) {
                    qlnv.lichsudangnhap();
                } else {
                    cout << " Ban khong co quyen dung chuc nang nay!" << endl;
                }
                break;
            case 9:
                if (chucvu == 1) {
                      qlnv.docfile();
                      cout << "Tong luong phai tra cho toan cong ty: " << qlnv.tinhtongluong() << endl;
                } else {
                    cout << "[-] Ban khong co quyen dung chuc nang nay!" << endl;
                }
                break;
            case 10:
              qlnv.tinhtongnhanvien();
               break;
                
             case 0:
                cout << "Da thoat chuong trinh." << endl;
                break;

            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
cout << "Ban co muon tiep tuc khong? (0: Co, 1: Khong): ";
        cin >> tiep;
        cin.ignore();
        if(tiep!=0){
            cout << "Da thoat chuong trinh." << endl;
        }
    } while (tiep ==0); 
    return 0;
}