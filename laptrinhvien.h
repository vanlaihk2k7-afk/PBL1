#include<iostream>
#include "nhanvien.h"
using namespace std;
class laptrinhvien: public nhanvien{
    private:
    string ngonngulaptrinh;
    int sogiolamthem;
    string vitridev;
    public:
    laptrinhvien();
    laptrinhvien(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, long long luongcoban, string ngonngulaptrinh, int sogiolamthem, string vitridev);
    ~laptrinhvien();
    void nhap();
    void xuat();
    long long tinhluong();
    string getngonngulaptrinh();
    int getsogiolamthem();
    string getvitridev();
    string getchucvu();
    string setngonngulaptrinh(string ngonngulaptrinh);
    int setsogiolamthem(int sogiolamthem);
    string setvitridev(string vitridev);
};
laptrinhvien::laptrinhvien(){
    this->setchucvu("lap trinh vien");
    ngonngulaptrinh="";
    sogiolamthem=0;
    vitridev="";
}
laptrinhvien::laptrinhvien(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, long long luongcoban, string ngonngulaptrinh, int sogiolamthem, string vitridev): nhanvien(name, gioitinh, tuoi, diachi, sdt, email, manv,"lap trinh vien", luongcoban){
    this->ngonngulaptrinh=ngonngulaptrinh;
    this->sogiolamthem=sogiolamthem;
    this->vitridev=vitridev;
}
laptrinhvien::~laptrinhvien(){
}
void laptrinhvien::nhap(){
    nhanvien::nhap();
    cout<<"Nhap ngon ngu lap trinh: ";
    getline(cin, ngonngulaptrinh);
    cout<<"Nhap so gio lam them: ";
    cin>>sogiolamthem;
    cin.ignore();
    cout<<"Nhap vi tri lap trinh: ";
    getline(cin, vitridev);
}
void laptrinhvien::xuat(){
    nhanvien::xuat();
    cout<<"Ngon ngu lap trinh: "<<ngonngulaptrinh<<endl;
    cout<<"So gio lam them: "<<sogiolamthem<<endl;
    cout<<"Vi tri lap trinh: "<<vitridev<<endl;
}
long long laptrinhvien::tinhluong(){
    return getluongcoban() + sogiolamthem*200000;
}
string laptrinhvien::getngonngulaptrinh(){
    return ngonngulaptrinh;
}
int laptrinhvien::getsogiolamthem(){
    return sogiolamthem;
}
string laptrinhvien::getvitridev(){
    return vitridev;
}
string laptrinhvien::getchucvu(){
    return "lap trinh vien";
}