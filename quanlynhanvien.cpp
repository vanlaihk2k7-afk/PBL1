#include<iostream>
using namespace std;
#include "gioithieu.h"
#include "baocao.h"
int main() {
    gioithieu();
    int chucvu = chonchucvu(); 
    system("cls");
    quanlynhanvien qlnv;
    int chon1;
    int chon2;
    int tiep;
    do {
        cout << "+==========================================================+" << endl;
        cout << "|         MENU QU?N L? NHÂN VIÊN CÔNG TY PH?N M?M          |" << endl;
        cout << "+====+=====================================================+" << endl;
        cout << "| STT|             CH?C NÃNG CHÝÕNG TR?NH                  |" << endl;
        cout << "+----+-----------------------------------------------------+" << endl;
        if(chucvu == 1) { 
            cout <<"| [1]| Nh?p danh sách nhân viên ban ð?u                    |" << endl;
            cout <<"| [2]| Xem danh sách nhân viên công ty                     |" << endl;
            cout <<"| [3]| T?m ki?m nhân viên                                  |" << endl;
            cout <<"| [4]| C?p nh?t thông tin nhân viên                        |" << endl;
            cout <<"| [5]| Thêm nhân viên                                      |" << endl;
            cout <<"| [6]| Xóa thông tin nhân viên                             |" << endl;
            cout <<"| [7]| Xem l?ch s? ðãng nh?p                               |" << endl;
            cout <<"| [8]| Xem báo cáo t? nhân viên                            |" << endl;
            cout <<"| [9]| T?ng lýõng c?a nhân viên trong công ty              |" << endl;
            cout <<"| [0]| Thoát chýõng tr?nh                                  |" << endl;
            cout <<"+----+-----------------------------------------------------+" << endl;
            cout << "Nh?p l?a ch?n c?a b?n: ";
            cin >> chon1;
            cin.ignore();
        } 
        else if(chucvu == 2) { 
            cout <<"| [1]| Xem thông tin cá nhân                               |" << endl;
            cout <<"| [2]| Báo cáo v?n ð? c?n gi?i quy?t                       |" << endl;
            cout <<"| [0]| Thoát chýõng tr?nh                                  |" << endl;
            cout <<"+----+-----------------------------------------------------+" << endl;
            cout << "Nh?p l?a ch?n c?a b?n: ";
            cin >> chon2;
            cin.ignore();
        }
        switch(chon1) {
            case 1:
            system("cls");
                if (chucvu == 1) {
                    qlnv.nhap();
                } else {
                    cout << "Ban khong co quyen dung chuc nang nay!" << endl;
                }
                break;
                
            case 2:
            system("cls"); 
               qlnv.docfile();
                qlnv.xuat(); 
                break;
            case 3: {
                system("cls");
                qlnv.timkiemtheomanv();
                break;
            }
            case 4:
                if (chucvu == 1) {
                    int mnv;
            while (true) {
                 cout << "Nh?p m? nhân viên c?a b?n: ";
               if (cin >> mnv && mnv > 0 && to_string(mnv).length() == 6) {
               cin.ignore(); 
               break;
           } else {
              cout << "Loi: Ma nhan vien phai la so nguyen duong va co 6 chu so. Vui long nhap lai!\n"; 
          }
       }
                     qlnv.updatenhanvien(mnv);
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
                    system("cls");
                    qlnv.lichsudangnhap();
                } else {
                    cout << " Ban khong co quyen dung chuc nang nay!" << endl;
                }
                break;
            case 8:
                if (chucvu == 1) {
                     system("cls");
                      docfilebaocao();
                } else {
                    cout << "[-] Ban khong co quyen dung chuc nang nay!" << endl;
                }
                break;
            case 9:
              qlnv.tinhtongluong();
               break;
            case 0:
                exit(0);
            default:
        switch(chon2){
            case 1:
            int mnv;
             while (true) {
            cout << "Nh?p m? nhân viên c?a b?n: ";
           if (cin >> mnv && mnv > 0 && to_string(mnv).length() == 6) {
            cin.ignore(); 
            break;
        } else {
            cout << "Loi: Ma nhan vien phai la so nguyen duong va co 6 chu so. Vui long nhap lai!\n"; 
        }
    }
            qlnv.timkiemtheomanv();
            break;
            case 2:
            ghifilebaocao(qlnv);
            break;
            case 0:
            exit(0);
        }
        }
        if(chon1!=0 && chon2!=0){
cout << "B?n có mu?n ti?p t?c không? (0: Có, 1: Không): ";
        cin >> tiep;
        system("cls");
        cin.ignore();
        if(tiep==1){
            cout << "B?n ð? thoát kh?i chýõng tr?nh." << endl;
        }
    }
    } while (tiep ==0); 
    return 0;
}