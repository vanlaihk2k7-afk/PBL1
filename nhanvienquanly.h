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
    nhanvienquanly(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, long long luongcoban, int soduanquanly, int sogiolamthem, int soduanhoanthanh);
    ~nhanvienquanly();
    void nhap();
    void xuat();
    long long tinhluong();
    string getchucvu();
    int getsoduanquanly();
    int getsogiolamthem();
    int getsoduanhoanthanh();
    int setsoduanquanly(int soduanquanly);
    int setsogiolamthem(int sogiolamthem);
    int setsoduanhoanthanh(int soduanhoanthanh);
};
nhanvienquanly::nhanvienquanly(){
    this->setchucvu("nhan vien quan ly");
    soduanquanly=0;
    sogiolamthem=0;
    soduanhoanthanh=0;
}
nhanvienquanly::nhanvienquanly(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, long long luongcoban, int soduanquanly, int sogiolamthem, int soduanhoanthanh): nhanvien(name, gioitinh, tuoi, diachi, sdt, email, manv,"nhan vien quan ly", luongcoban){
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
    cout<<"Nhap so du an quan ly: ";
    cin>>soduanquanly;
    a++;
        }
        else{
            cout<<"Nhap lai so du an quan ly: ";
            cin>>soduanquanly;
        }
    }while(soduanquanly<0);

    cin.ignore();
    cout<<"Nhap so gio lam them: ";
    cin>>sogiolamthem;
    cin.ignore();

    int i=0;
    do{
        if(i==0){
        cout<<"Nhap so du an hoan thanh: ";
        cin>>soduanhoanthanh;
        i++;
        }
        else{cout<<"nhap lai so du an hoan thanh(so du an hoan thanh khong duoc nhieu hon so du an quan ly): ";
        cin>>soduanhoanthanh;}

    }while (soduanhoanthanh > soduanquanly);
    
    cin.ignore();
}
void nhanvienquanly::xuat(){
    nhanvien::xuat();
    cout<<"So du an quan ly: "<<soduanquanly<<endl;
    cout<<"So gio lam them: "<<sogiolamthem<<endl;
    cout<<"So du an hoan thanh: "<<soduanhoanthanh<<endl;
}
long long nhanvienquanly::tinhluong(){
    return getluongcoban() + sogiolamthem*300000 + soduanhoanthanh*500000;
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