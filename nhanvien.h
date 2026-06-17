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
    double luongcoban;
    double luongthucte;
    public:
    nhanvien();
    nhanvien(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, double luongcoban);
    virtual ~nhanvien();
    virtual void nhap();
    virtual void xuat();
    virtual double tinhluong()=0;
    double getluongcoban();
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
    void setluongcoban(double luongcoban);
    void setluongthucte(double luongthucte);
};
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
}
nhanvien::nhanvien(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, double luongcoban){
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
}
void nhanvien::nhap() {
    while (true) {
        cout << "Nhập tên nhân viên: ";
        getline(cin, name);
        bool tentrue = !name.empty();
        for (char c : name) {
            if (isdigit(c)) {
                tentrue = false;
                break;
            }
        }
        if (tentrue) break;
        cout << "Loi: Ten khong hop le (khong chua so hay ky tu dac biet). Vui long nhap lai!"<<endl;
    }

    int chonGioiTinh; 
    while (true) {
        cout << "Nhập giới tính (0: Nam, 1: Nữ): ";
        if (cin >> chonGioiTinh && (chonGioiTinh == 0 || chonGioiTinh == 1)) {
            cin.ignore();
            gioitinh = (chonGioiTinh == 1); //nếu chọn 1 thì gioitinh=true(Nữ)chọn 0 thì gioitinh=false(Nam)
            break;
        } else {
            cout << "Giới tính không hợp lệ. Chỉ được phép nhập 0 (Nam) hoac 1 (Nữ)"<<endl;
        }
    }
    int i=0;
    do{
        if(i==0){
    cout << "Nhập tuổi: ";
    cin >> tuoi;
    cin.ignore();
    i++;
        }
        else{
            cout << "Nhập lại thuổi: ";
            cin >> tuoi;
            cin.ignore();
        }
    }while(tuoi < 18 || tuoi > 65);


    cout << "Nhập địa chỉ của bạn: ";
    getline(cin, diachi);
    
    while (true) {
        cout << "Nhập số điện thoại: ";
        getline(cin, sdt);
        bool sdtHopLe = !sdt.empty() && sdt.length() == 10; 
        for (char c : sdt) {
            if (!isdigit(c)) { 
                sdtHopLe = false;
                break;
            }
        }
        if (sdtHopLe) break;
        cout << "Số điện thoại không hợp lệ. Vui lòng nhập lại"<<endl;
    }

    while (true) {
    cout << "Nhập email: ";
    getline(cin, email);
    //tìm vị trí của chuỗi "@gmail.com" trong email
    size_t timkiem = email.find("@gmail.com");

    if (timkiem != string::npos && timkiem == email.length() - 10) {
        break;
    } else {
    cout << "Lỗi: email phải có đuôi @gmail.com. Vui lòng nhập lại"<<endl;
}
    }
    while (true) {
        cout << "Nhập mã nhân viên của bạn(6 số): ";
        if (cin >> manv && manv > 0 && to_string(manv).length() == 6) {
            cin.ignore(); 
            break;
        } else {
            cout << "Mã nhân viên của bạn chưa hợp lệ. Vui lòng nhập lại"<<endl; 
        }
    }

    while (true) {
        cout << "Nhập lương cơ bản (Triệu đồng): ";
        if (cin >> luongcoban && luongcoban >= 0) {
            cin.ignore(); 
            break;
        } else {
            cout << "Lỗi: Lương cơ bản phải >0";
        }
    }
}
void nhanvien::xuat(){
    cout<<"Tên nhân viên: "<<name<<endl;
    cout<<"Giới tính: "<<(gioitinh ? "Nữ" : "Nam")<<endl;
    cout<<"Tuổi: "<<tuoi<<endl;
    cout<<"Địa chỉ: "<<diachi<<endl;
    cout<<"Số điện thoại: "<<sdt<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Mã nhân viên: "<<manv<<endl;
    cout<<"Chức vụ: "<<chucvu<<endl;
    cout<<"Lương cơ bản: "<<luongcoban<<" Triệu đồng"<<endl;
}
double nhanvien::getluongcoban(){
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
void nhanvien::setluongcoban(double luongcoban){
    this->luongcoban=luongcoban;
}

