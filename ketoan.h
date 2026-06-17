#include<iostream>
#include "nhanvien.h"
using namespace std;
class ketoan: public nhanvien{
    private:
    string chuyennganh;
    int sogiolamthem;
    public:
    ketoan();
    ketoan(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, double luongcoban, string chuyennganh, int sogiolamthem);
    ~ketoan();
    void nhap();
    void xuat();
    double tinhluong();
    string getchuyennganh();
    int getsogiolamthem();
    string getchucvu();
    void setchuyennganh(string chuyennganh);
    void setsogiolamthem(int sogiolamthem);
};
ketoan::ketoan(){
    this->setchucvu("ke toan");
    chuyennganh="";
    sogiolamthem=0;
}
ketoan::ketoan(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, double luongcoban, string chuyennganh, int sogiolamthem): nhanvien(name, gioitinh, tuoi, diachi, sdt, email, manv,"ke toan", luongcoban){
    this->chuyennganh=chuyennganh;
    this->sogiolamthem=sogiolamthem;
}
ketoan::~ketoan(){
}
void ketoan::nhap(){
    nhanvien::nhap();
    cout<<"Nhập chuyên ngành của bạn: ";
    getline(cin, chuyennganh);
    cout<<"Nhập số giờ làm thêm: ";
    cin>>sogiolamthem;
    cin.ignore();
}
void ketoan::xuat(){
    nhanvien::xuat();
    cout<<"Chuyen nganh: "<<chuyennganh<<endl;
    cout<<"So gio lam them: "<<sogiolamthem<<endl;
}
double ketoan::tinhluong(){
    return getluongcoban() + sogiolamthem*0.2;
}
string ketoan::getchuyennganh(){
    return chuyennganh;
}
int ketoan::getsogiolamthem(){
    return sogiolamthem;
}
string ketoan::getchucvu(){
    return "ke toan";
}
void ketoan::setchuyennganh(string chuyennganh){
    this->chuyennganh=chuyennganh;
}
void ketoan::setsogiolamthem(int sogiolamthem){
    this->sogiolamthem=sogiolamthem;
}
