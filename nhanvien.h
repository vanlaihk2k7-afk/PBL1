#pragma once
#include <iostream>
using namespace std;
class nhanvien{
    private:
    string name;
    bool gioitinh;
    int tuoi;
    string diachi;
    string sdt;
    string email;
    int manv;
    string chucvu;
    long long luongcoban;
    public:
    static int tongnv;
    nhanvien();
    nhanvien(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, long long luongcoban);
    virtual ~nhanvien();
    virtual void nhap();
    virtual void xuat();
    virtual long long tinhluong()=0;
    long long getluongcoban();
    int getmanv();
    string getten();
    bool getgioitinh();
    int gettuoi();
    string getdiachi();
    string getsdt();
    string getemail();
    string getchucvu();
    void setten(string name);
    void setgioitinh(bool gioitinh);
    void settuoi(int tuoi);
    void setdiachi(string diachi);
    void setsdt(string sdt);
    void setemail(string email);
    void setmanv(int manv);
    void setchucvu(string chucvu);
    void setluongcoban(long long luongcoban);
    static int gettongnv();
};
int nhanvien::tongnv=0;
nhanvien::nhanvien(){
    name="";
    gioitinh=false;
    tuoi=0;
    diachi="";
    sdt="";
    email="";
    chucvu="";
    manv=0;
    luongcoban=0;
    tongnv++;
}
nhanvien::nhanvien(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, long long luongcoban){
    this->name=name;
    this->gioitinh=gioitinh;
    this->tuoi=tuoi;
    this->diachi=diachi;
    this->sdt=sdt;
    this->email=email;
    this->manv=manv;
    this->chucvu=chucvu;
    this->luongcoban=luongcoban;
}
nhanvien::~nhanvien(){
    tongnv--;
}
void nhanvien::nhap() {
    while (true) {
        cout << "Nhap ten nhan vien: ";
        getline(cin, name);
        bool tentrue = !name.empty();
        for (char c : name) {
            if (!isalpha(c) && !isspace(c)) {
                tentrue = false;
                break;
            }
        }
        if (tentrue) break;
        cout << "Loi: Ten khong hop le (khong chua so hay ky tu dac biet). Vui long nhap lai!";
    }

    int chonGioiTinh; 
    while (true) {
        cout << "Nhap gioi tinh (0: Nam, 1: Nu): ";
        if (cin >> chonGioiTinh && (chonGioiTinh == 0 || chonGioiTinh == 1)) {
            cin.ignore();
            gioitinh = (chonGioiTinh == 1); // Nếu chọn 1 thì gioitinh = true (Nữ), chọn 0 thì gioitinh = false (Nam)
            break;
        } else {
            cout << "-> Lỗi: Gioi tinh khong hop le! Chi duoc phep nhap 0 (Nam) hoac 1 (Nu).\n";
        }
    }
    int i=0;
    do{
        if(i==0){
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cin.ignore();
    i++;
        }
        else{
            cout << "Nhap lai tuoi: ";
            cin >> tuoi;
            cin.ignore();
        }
    }while(tuoi < 18 || tuoi > 65);


    cout << "Nhap dia chi: ";
    getline(cin, diachi);
    
    while (true) {
        cout << "Nhap so dien thoai: ";
        getline(cin, sdt);
        bool sdtHopLe = !sdt.empty() && sdt.length() == 10; 
        for (char c : sdt) {
            if (!isdigit(c)) { 
                sdtHopLe = false;
                break;
            }
        }
        if (sdtHopLe) break;
        cout << "So dien thoai khong hop le! Vui long nhap lai.\n";
    }

    while (true) {
    cout << "Nhap email: ";
    getline(cin, email);

    // 1. Tìm vị trí của chuỗi "@gmail.com" trong email
    size_t pos = email.find("@gmail.com");

    // 2. Kiểm tra xem "@gmail.com" có tồn tại và nằm ở cuối chuỗi hay không
    if (pos != string::npos && pos == email.length() - 10) {
        break;
    } else {
    cout << " loi: Email phai co duoi @gmail.com. Vui long nhap lai!\n";
}
    }
    while (true) {
        cout << "Nhap ma nhan vien: ";
        if (cin >> manv && manv > 0 && to_string(manv).length() == 6) {
            cin.ignore(); 
            break;
        } else {
            cout << "Loi: Ma nhan vien phai la so nguyen duong va co 6 chu so. Vui long nhap lai!\n"; 
        }
    }

    while (true) {
        cout << "Nhap luong co ban(don vi: trieu dong): ";
        if (cin >> luongcoban && luongcoban >= 0) {
            cin.ignore(); 
            break;
        } else {
            cout << " Loi: Luong co ban phai >= 0. Vui long nhap lai!\n";
        }
    }
}
void nhanvien::xuat(){
    cout<<"Ten nhan vien: "<<name<<endl;
    cout<<"Gioi tinh: "<<(gioitinh ? "Nữ" : "Nam")<<endl;
    cout<<"Tuoi: "<<tuoi<<endl;
    cout<<"Dia chi: "<<diachi<<endl;
    cout<<"So dien thoai: "<<sdt<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Ma nhan vien: "<<manv<<endl;
    cout<<"Chuc vu: "<<chucvu<<endl;
    cout<<"Luong co ban: "<<luongcoban<<endl;
}
long long nhanvien::getluongcoban(){
    return luongcoban;
}
int nhanvien::getmanv(){
    return manv;
}
string nhanvien::getten(){
    return name;
}
bool nhanvien::getgioitinh(){
    return gioitinh;
}
int nhanvien::gettuoi(){
    return tuoi;
}
string nhanvien::getdiachi(){
    return diachi;
}
string nhanvien::getsdt(){
    return sdt;
}
string nhanvien::getemail(){
    return email;
}
string nhanvien::getchucvu(){
    return chucvu;
}
void nhanvien::setten(string name){
    this->name=name;
}
void nhanvien::setgioitinh(bool gioitinh){
    this->gioitinh=gioitinh;
}
void nhanvien::settuoi(int tuoi){
    this->tuoi=tuoi;
}
void nhanvien::setdiachi(string diachi){
    this->diachi=diachi;
}
void nhanvien::setsdt(string sdt){
    this->sdt=sdt;
}
void nhanvien::setemail(string email){
    this->email=email;
}
void nhanvien::setmanv(int manv){
    this->manv=manv;
}
void nhanvien::setchucvu(string chucvu){
    this->chucvu=chucvu;
}
void nhanvien::setluongcoban(long long luongcoban){
    this->luongcoban=luongcoban;
}
int nhanvien::gettongnv(){
    return tongnv;
}

