#include<iostream>
#include "nhanvien.h"
using namespace std;
class kiemthuvien: public nhanvien{
    private:
    string chuyennganh;
    int soloiphathien;
    int sogiolamthem;
    public:
    kiemthuvien();
    kiemthuvien(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, double luongcoban, string chuyennganh, int sogiolamthem, int soloiphathien);
    ~kiemthuvien();
    void nhap();
    void xuat();
    double tinhluong();
    string getchuyennganh();
    int getsoloiphathien();
    int getsogiolamthem();
    string getchucvu();
    void setchuyennganh(string chuyennganh);
    void setsoloiphathien(int soloiphathien);
    void setsogiolamthem(int sogiolamthem);
};
kiemthuvien::kiemthuvien(){
    this->setchucvu("kiem thu vien");
    chuyennganh="";
    soloiphathien=0;
    sogiolamthem=0;
}
kiemthuvien::kiemthuvien(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, double luongcoban, string chuyennganh, int sogiolamthem, int soloiphathien): nhanvien(name, gioitinh, tuoi, diachi, sdt, email, manv,"kiem thu vien", luongcoban){
    this->chuyennganh=chuyennganh;
    this->soloiphathien=soloiphathien;
    this->sogiolamthem=sogiolamthem;
}
kiemthuvien::~kiemthuvien(){
}
void kiemthuvien::nhap(){
    nhanvien::nhap();
    cout<<"Nh?p chuyên ngành h?c c?a b?n: ";
    getline(cin, chuyennganh);
    cout<<"Nh?p s? l?i phát hi?n và s?a ðý?c: ";
    cin>>soloiphathien;
    cin.ignore();
    cout<<"Nh?p s? gi? làm thêm: ";
    cin>>sogiolamthem;
    cin.ignore();
}
void kiemthuvien::xuat(){
    nhanvien::xuat();
    cout<<"Chuyen nganh: "<<chuyennganh<<endl;
    cout<<"So loi phat hien: "<<soloiphathien<<endl;
    cout<<"So gio lam them: "<<sogiolamthem<<endl;
}
double kiemthuvien::tinhluong(){
    return getluongcoban() + sogiolamthem*0.3 - soloiphathien*0.1;
}
string kiemthuvien::getchuyennganh(){
    return chuyennganh;
}
int kiemthuvien::getsoloiphathien(){
    return soloiphathien;
}
int kiemthuvien::getsogiolamthem(){
    return sogiolamthem;
}
string kiemthuvien::getchucvu(){
    return "kiem thu vien";
}
void kiemthuvien::setchuyennganh(string chuyennganh){
    this->chuyennganh=chuyennganh;
}
void kiemthuvien::setsoloiphathien(int soloiphathien){
    this->soloiphathien=soloiphathien;
}
void kiemthuvien::setsogiolamthem(int sogiolamthem){
    this->sogiolamthem=sogiolamthem;
}