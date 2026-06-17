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
    laptrinhvien(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, double luongcoban, string ngonngulaptrinh, int sogiolamthem, string vitridev);
    ~laptrinhvien();
    void nhap();
    void xuat();
    double tinhluong();
    string getngonngulaptrinh();
    int getsogiolamthem();
    string getvitridev();
    string getchucvu();
    void setngonngulaptrinh(string ngonngulaptrinh);
    void setsogiolamthem(int sogiolamthem);
    void setvitridev(string vitridev);
};
laptrinhvien::laptrinhvien(){
    this->setchucvu("lap trinh vien");
    ngonngulaptrinh="";
    sogiolamthem=0;
    vitridev="";
}
laptrinhvien::laptrinhvien(string name, bool gioitinh, int tuoi, string diachi, string sdt, string email, int manv, string chucvu, double luongcoban, string ngonngulaptrinh, int sogiolamthem, string vitridev): nhanvien(name, gioitinh, tuoi, diachi, sdt, email, manv,"lap trinh vien", luongcoban){
    this->ngonngulaptrinh=ngonngulaptrinh;
    this->sogiolamthem=sogiolamthem;
    this->vitridev=vitridev;
}
laptrinhvien::~laptrinhvien(){
}
void laptrinhvien::nhap(){
    nhanvien::nhap();
    cout<<"Nhập ngôn ngữ lập trình: ";
    getline(cin, ngonngulaptrinh);
    cout<<"Nhập số giờ làm thêm: ";
    cin>>sogiolamthem;
    cin.ignore();
    cout<<"Nhập vị trí lập trình của bạn: ";
    getline(cin, vitridev);
}
void laptrinhvien::xuat(){
    nhanvien::xuat();
    cout<<"Ngôn ngữ lập trình: "<<ngonngulaptrinh<<endl;
    cout<<"Số giờ làm thêm: "<<sogiolamthem<<endl;
    cout<<"Vị trí lập trình: "<<vitridev<<endl;
}
double laptrinhvien::tinhluong(){
    return getluongcoban() + sogiolamthem*0.4;
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
void laptrinhvien::setngonngulaptrinh(string ngonngulaptrinh){
    this->ngonngulaptrinh=ngonngulaptrinh;
}
void laptrinhvien::setsogiolamthem(int sogiolamthem){
    this->sogiolamthem=sogiolamthem;
}
void laptrinhvien::setvitridev(string vitridev){
    this->vitridev=vitridev;
}