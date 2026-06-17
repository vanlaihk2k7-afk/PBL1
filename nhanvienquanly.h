#include<iostream>
#include "nhanvien.h"
using namespace std;
class nhanvienquanly: public nhanvien{
    private:
    int soduanquanly;
    int sogiolamthem;
    int soduanhoanthanh;
    public:
    nhanvienquanly();
    nhanvienquanly(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, double luongcoban, int soduanquanly, int sogiolamthem, int soduanhoanthanh);
    ~nhanvienquanly();
    void nhap();
    void xuat();
    double tinhluong();
    string getchucvu();
    int getsoduanquanly();
    int getsogiolamthem();
    int getsoduanhoanthanh();
    void setsoduanquanly(int soduanquanly);
    void setsogiolamthem(int sogiolamthem);
    void setsoduanhoanthanh(int soduanhoanthanh);
};
nhanvienquanly::nhanvienquanly(){
    this->setchucvu("nhan vien quan ly");
    soduanquanly=0;
    sogiolamthem=0;
    soduanhoanthanh=0;
}
nhanvienquanly::nhanvienquanly(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, double luongcoban, int soduanquanly, int sogiolamthem, int soduanhoanthanh): nhanvien(name, gioitinh, tuoi, diachi, sdt, email, manv,"nhan vien quan ly", luongcoban){
    this->soduanquanly=soduanquanly;
    this->sogiolamthem=sogiolamthem;
    this->soduanhoanthanh=soduanhoanthanh;
}
nhanvienquanly::~nhanvienquanly(){
}
void nhanvienquanly::nhap(){
    nhanvien::nhap();
    int a=0;
    do{
        if(a==0){
    cout<<"Nhập số dự án quản lý: ";
    cin>>soduanquanly;
    a++;
        }
        else{
            cout<<"Nhập lại số dự án quản lý: ";
            cin>>soduanquanly;
        }
    }while(soduanquanly<0);

    cin.ignore();
    cout<<"Nhập số giờ làm thêm: ";
    cin>>sogiolamthem;
    cin.ignore();

    int i=0;
    do{
        if(i==0){
        cout<<"Nhập số dự án hoàn thành: ";
        cin>>soduanhoanthanh;
        i++;
        }
        else{cout<<"Nhập lại số dự án bạn đã hoàn thành(nhỏ hơn số dự án bạn quản lý): ";
        cin>>soduanhoanthanh;}

    }while (soduanhoanthanh > soduanquanly);
    
    cin.ignore();
}
void nhanvienquanly::xuat(){
    nhanvien::xuat();
    cout<<"Số dự án quản lý: "<<soduanquanly<<endl;
    cout<<"Số giờ đã làm thêm: "<<sogiolamthem<<endl;
    cout<<"Số dự án đã hoàn thành: "<<soduanhoanthanh<<endl;
}
double nhanvienquanly::tinhluong(){
    return getluongcoban() + sogiolamthem*0.3 + soduanhoanthanh*0.5;
}
string nhanvienquanly::getchucvu(){
    return "nhan vien quan ly";
}
int nhanvienquanly::getsoduanquanly(){
    return soduanquanly;
}
int nhanvienquanly::getsogiolamthem(){
    return sogiolamthem;
}
int nhanvienquanly::getsoduanhoanthanh(){
    return soduanhoanthanh;
}
void nhanvienquanly::setsoduanquanly(int soduanquanly){
    this->soduanquanly=soduanquanly;
}
void nhanvienquanly::setsogiolamthem(int sogiolamthem){
    this->sogiolamthem=sogiolamthem;
}
void nhanvienquanly::setsoduanhoanthanh(int soduanhoanthanh){
    this->soduanhoanthanh=soduanhoanthanh;
}