#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include"quanlynhanvien.h"
using namespace std;
void docfilebaocao(){
    ifstream file("baocao.txt");
    if (!file.is_open()) {
        cout << "không thể mở file!" << endl;
        return;
    }
    string thuocdong(18,' ');
    string line;
    cout  <<thuocdong << "NỘI DUNG BÁO CÁO" << endl;
    cout  << "+----------------------------------------------------------+" << endl;
    while (getline(file, line)) {
        if (line.empty()) continue; 
        cout << "| " << left << setw(61) << line << " |" << endl;
    }
    cout << "+----------------------------------------------------------+" << endl;
    file.close();
}
void ghifilebaocao(quanlynhanvien &ql){
    int manv;
    string nd;
    while (true) {
            cout << "Nhập mã nhân viên của bạn: ";
           if (cin >> manv && manv > 0 && to_string(manv).length() == 6) {
            cin.ignore(); 
            break;
        } else {
            cout << "Loi: Ma nhan vien phai la so nguyen duong va co 6 chu so. Vui long nhap lai!\n"; 
        }
    }
    ql.timkiemtheomanv(manv);
    system("cls");
    cout<<"Nhập nội dung báo cáo: ";
    getline(cin,nd);
    ofstream file("baocao.txt", ios::app); 
    if (file.is_open()) {
        file << "Mã NV: " <<manv<<"- Nội dung báo cáo: "<<nd<<endl;
        file.close();
    } else {
        cout << "Không thể ghi file!" << endl;
    }
}
