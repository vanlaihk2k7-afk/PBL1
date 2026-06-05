
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
string key;
string username;
void docfilelichsu(){
    ifstream file("lichsudangnhap.txt");
    if (!file.is_open()) {
        cout << "Loi: Khong the mo file hoac file chua ton tai!" << endl;
        return;
    }
    string thuocdong(18,' ');
    string line;
    cout  <<thuocdong << "LICH SU DANG NHAP" << endl;
    cout  << "+----------------------------------------------------+" << endl;
    while (getline(file, line)) {
        if (line.empty()) continue; 
        cout << "| " << left << setw(50) << line << " |" << endl;
    }
    cout << "+----------------------------------------------------+" << endl;
    file.close();
}
void ghifilelichsu(){
    ofstream file("lichsudangnhap.txt", ios::app); 
    if (file.is_open()) {
        file << "Username: " << username << " - Dang nhap thanh cong!" << endl;
        file.close();
    } else {
        cout << "Loi: Khong the mo file de ghi!" << endl;
    }
}

void kiemTraDangNhapquanly(){
    cout<<"Username: ";
        getline(cin, username);
    do {
    cout << "Password: ";
    getline(cin, key);
    if (key == "123456") {
        cout << "Dang nhap thanh cong!" << endl;
        ghifilelichsu(); // Ghi lịch sử đăng nhập vào file
    } else {
        cout << "Mat khau sai! Vui long thu lai." << endl;
    }
} while (key != "123456");
}
void kiemTraDangNhapnhanvien(){
    cout<<"Username: ";
        getline(cin, username);
    do {
    cout << "Password: ";
    getline(cin, key);
    if (key == "123") {
        cout << "Dang nhap thanh cong!" << endl;
        ghifilelichsu(); // Ghi lịch sử đăng nhập vào file
    } else {
        cout << "Mat khau sai! Vui long thu lai." << endl;
    }
} while (key != "123");
}
int chonchucvu(){
    int chucvu;
    cout << "Chon chuc vu (1: Quan ly, 2: Nhan vien): ";
    cin >> chucvu;
    cin.ignore();
    switch(chucvu) {
        case 1:
            kiemTraDangNhapquanly();
            return 1;
        case 2:
            kiemTraDangNhapnhanvien();
            return 2;
        default:
            cout << "Lua chon khong hop le! Vui long thu lai." << endl;
            return chonchucvu(); 
    }
}
