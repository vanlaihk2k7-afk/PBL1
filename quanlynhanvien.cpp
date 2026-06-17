#include<iostream>
using namespace std;
#include "gioithieu.h"
#include "baocao.h"
int main() {
    gioithieu();
    int chucvu = chonchucvu(); 
    system("cls");
    quanlynhanvien qlnv;
    qlnv.docfile();
    int luachon;
    int tiep;
    do {
        cout << "+==========================================================+" << endl;
        cout << "|         MENU QUẢN LÝ NHÂN VIÊN CÔNG TY PHẦN MỀM          |" << endl;
        cout << "+====+=====================================================+" << endl;
        cout << "| STT|             CHỨC NĂNG CHƯƠNG TRÌNH                    |" << endl;
        cout << "+----+-----------------------------------------------------+" << endl;
        if(chucvu == 1) { 
            cout <<"| [1]| Nhập danh sách nhân viên ban đầu                    |" << endl;
            cout <<"| [2]| Xem danh sách nhân viên công ty                     |" << endl;
            cout <<"| [3]| Tìm kiếm nhân viên                                  |" << endl;
            cout <<"| [4]| Cập nhật thông tin nhân viên                        |" << endl;
            cout <<"| [5]| Thêm nhân viên                                      |" << endl;
            cout <<"| [6]| Xóa thông tin nhân viên                             |" << endl;
            cout <<"| [7]| Xem lịch sử đăng nhập                               |" << endl;
            cout <<"| [8]| Xem báo cáo của nhân viên                           |" << endl;
            cout <<"| [9]| Tính lương của nhân viên trong công ty              |" << endl;
            cout <<"| [0]| Thoát chương trình                                  |" << endl;
            cout <<"+----+-----------------------------------------------------+" << endl;
            cout << "Nhập lựa chọn của bạn: ";
            cin >> luachon;
            cin.ignore();
        } 
        else if(chucvu == 2) { 
            cout <<"| [1]| Xem thông tin cá nhân                               |" << endl;
            cout <<"| [2]| Báo cáo vấn đề cần giải quyết                       |" << endl;
            cout <<"| [0]| Thoát chương trình                                  |" << endl;
            cout <<"+----+-----------------------------------------------------+" << endl;
            cout << "Nhập lựa chọn của bạn: ";
            cin >> luachon;
            cin.ignore();
        }
        if(chucvu==1){
        switch(luachon) {
            case 1:
            system("cls");
                if (chucvu == 1) {
                    qlnv.nhap();
                } else {
                    cout << "Bạn không có quyền truy cập chức năng này" << endl;
                }
                break;
                
            case 2:
            system("cls"); 
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
                 cout << "Nhập mã nhân viên của bạn: ";
               if (cin >> mnv && mnv > 0 && to_string(mnv).length() == 6) {
               cin.ignore(); 
               break;
           } else {
              cout << "Lỗi: Mã nhân viên phải 6 số. Vui lòng nhập lại"<<endl; 
          }
       }
                     qlnv.updatenhanvien(mnv);
                } else {
                    cout << "Bạn không có quyền truy cập chức năng này" << endl;
                }
                break;
                
            case 5:
                if (chucvu == 1) {
                    qlnv.addnhanvien();
                } else {
                    cout << "Bạn không có quyền truy cập chức năng này" << endl;
                }
                break;
            case 6:
                if (chucvu == 1) {
                    int manv;
                    cout << "Nhập mã nhân viên cần xóa: ";
                    cin >> manv;
                    cin.ignore();
                    qlnv.deletenhanvien(manv);
                } else {
                    cout <<"Bạn không có quyền truy cập chức năng này" << endl;
                }
                break;
            case 7: 
                if (chucvu == 1) {
                    system("cls");
                    qlnv.lichsudangnhap();
                } else {
                    cout <<"Bạn không có quyền truy cập chức năng này"<<endl;
                }
                break;
            case 8:
                if (chucvu == 1) {
                     system("cls");
                      docfilebaocao();
                } else {
                    cout <<"Bạn không có quyền truy cập chức năng này"<<endl;
                }
                break;
            case 9:
             if (chucvu == 1) {
              cout<<"TỔNG SỐ TIỀN CẦN PHẢI TRẢ CHO NHÂN VIÊN LÀ: "<<qlnv.tinhtongluong()<<" triệu đồng"<<endl;
             }
               break;
            case 0:
                exit(0);
            default: cout<<"Lựa chọn không hợp lệ";
        }
    }
        else{
        switch(luachon){
            case 1:
            qlnv.timkiemtheomanv();
            break;
            case 2:
            ghifilebaocao(qlnv);
            break;
            case 0:
            exit(0);
        }
        }
  cout << "Bạn có muốn tiếp tục không? (1: Có, 0: Không): ";
        cin >> tiep;
        cin.ignore();
        system("cls");
        if(tiep==0){
            cout << "Bạn đã thoát." << endl;
            break;
        }
    } while (tiep ==1); 
    return 0;

}