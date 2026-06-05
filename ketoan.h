#include<iostream>
#include "nhanvien.h"
using namespace std;
class ketoan: public nhanvien{
    private:
    string chuyennganh;
    int sogiolamthem;
    public:
    ketoan();
    ketoan(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, long long luongcoban, string chuyennganh, int sogiolamthem);
    ~ketoan();
    void nhap();
    void xuat();
    long long tinhluong();
    string getchuyennganh();
    int getsogiolamthem();
    string getchucvu();
    string setchuyennganh(string chuyennganh);
    int setsogiolamthem(int sogiolamthem);
    
};
ketoan::ketoan(){
    this->setchucvu("ke toan");
    chuyennganh="";
    sogiolamthem=0;
}
ketoan::ketoan(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, long long luongcoban, string chuyennganh, int sogiolamthem): nhanvien(name, gioitinh, tuoi, diachi, sdt, email, manv,"ke toan", luongcoban){
    this->chuyennganh=chuyennganh;
    this->sogiolamthem=sogiolamthem;
}
ketoan::~ketoan(){
}
void ketoan::nhap(){
    nhanvien::nhap();
    cout<<"Nhap chuyen nganh: ";
    getline(cin, chuyennganh);
    cout<<"Nhap so gio lam them: ";
    cin>>sogiolamthem;
    cin.ignore();
}
void ketoan::xuat(){
    nhanvien::xuat();
    cout<<"Chuyen nganh: "<<chuyennganh<<endl;
    cout<<"So gio lam them: "<<sogiolamthem<<endl;
}
long long ketoan::tinhluong(){
    return getluongcoban() + sogiolamthem*100000;
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
