
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
        cout << "không thể mở" << endl;
        return;
    }
    string thuocdong(18,' ');
    string line;
    cout  <<thuocdong << "LỊCH SỬ ĐĂNG NHẬP" << endl;
    cout  << "+----------------------------------------------------+" << endl;
    while (getline(file, line)) {
        if (line.empty()) continue; 
        cout << "| " << left << setw(58) << line << " |" << endl;
    }
    cout << "+----------------------------------------------------+" << endl;
    file.close();
}
void ghifilelichsu(){
    ofstream file("lichsudangnhap.txt", ios::app); 
    if (file.is_open()) {
        file << "Username: " << username << " - Đã đăng nhập thành công!" << endl;
        file.close();
    } else {
        cout << "Không thể ghi file!" << endl;
    }
}

void kiemTraDangNhapquanly(){
    system("cls");
    cout<<"Đăng nhập bằng tài khoản quản lý"<<endl;
    cout<<"Username: ";
        getline(cin, username);
    do {
    cout << "Password: ";
    getline(cin, key);
    if (key == "123456") {
        cout << "Đăng nhập thành công!" << endl;
        ghifilelichsu(); // Ghi lịch sử đăng nhập vào file lichsudangnhap.txt
    } else {
        cout << "Mật khẩu sai. Vui lòng thử lại!" << endl;
    }
} while (key != "123456");
}
void kiemTraDangNhapnhanvien(){
    system("cls");
    cout<<"Đăng nhập bằng tài khoản nhân viên"<<endl;
    cout<<"Username: ";
        getline(cin, username);
    do {
    cout << "Password: ";
    getline(cin, key);
    if (key == "123") {
        cout << "Đăng nhập thành công!" << endl;
        ghifilelichsu();
    } else {
        cout << "Mật khẩu sai. Vui lòng thử lại!" << endl;
    }
} while (key != "123");
}
int chonchucvu(){
    int chucvu;
    cout<<"+----------MENU CHÍNH----------+"<<endl;
    cout<<"|"<<"Chức vụ:"<<setw(23)<<"|"<<endl;
    cout<<"|"<<"1:Quản lý"<<setw(22)<<"|"<<endl;
    cout<<"|"<<"2:Nhân viên"<<setw(20)<<"|"<<endl;
    cout<<"|"<<"0:Thoát"<<setw(24)<<"|"<<endl;
    cout<<"+------------------------------+"<<endl;
    cout << "Vui lòng chọn chức vụ của bạn:";
    cin >> chucvu;
    cin.ignore();
    switch(chucvu) {
        case 1:
            kiemTraDangNhapquanly();
            return 1;
        case 2:
            kiemTraDangNhapnhanvien();
            return 2;
        case 0:
        cout<<"Đã thoát";
            exit(0);
        default:
            cout << "Lựa chọn của bạn không hợp lệ. Vui lòng thử lại." << endl;
            return chonchucvu(); 
    }
}
