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
    kiemthuvien(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, long long luongcoban, string chuyennganh, int sogiolamthem, int soloiphathien);
    ~kiemthuvien();
    void nhap();
    void xuat();
    long long tinhluong();
    string getchuyennganh();
    int getsoloiphathien();
    int getsogiolamthem();
    string getchucvu();
    string setchuyennganh(string chuyennganh);
    int setsoloiphathien(int soloiphathien);
    int setsogiolamthem(int sogiolamthem);
};
kiemthuvien::kiemthuvien(){
    this->setchucvu("kiem thu vien");
    chuyennganh="";
    soloiphathien=0;
    sogiolamthem=0;
}
kiemthuvien::kiemthuvien(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, long long luongcoban, string chuyennganh, int sogiolamthem, int soloiphathien): nhanvien(name, gioitinh, tuoi, diachi, sdt, email, manv,"kiem thu vien", luongcoban){
    this->chuyennganh=chuyennganh;
    this->soloiphathien=soloiphathien;
    this->sogiolamthem=sogiolamthem;
}
kiemthuvien::~kiemthuvien(){
}
void kiemthuvien::nhap(){
    nhanvien::nhap();
    cout<<"Nhap chuyen nganh: ";
    getline(cin, chuyennganh);
    cout<<"Nhap so loi phat hien: ";
    cin>>soloiphathien;
    cin.ignore();
    cout<<"Nhap so gio lam them: ";
    cin>>sogiolamthem;
    cin.ignore();
}
void kiemthuvien::xuat(){
    nhanvien::xuat();
    cout<<"Chuyen nganh: "<<chuyennganh<<endl;
    cout<<"So loi phat hien: "<<soloiphathien<<endl;
    cout<<"So gio lam them: "<<sogiolamthem<<endl;
}
long long kiemthuvien::tinhluong(){
    return getluongcoban() + sogiolamthem*150000 - soloiphathien*50000;
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
