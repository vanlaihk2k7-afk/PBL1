#include<iostream>
#include "laptrinhvien.h"
#include "kiemthuvien.h"
#include "ketoan.h"
#include "nhanvienquanly.h"
#include "baomat.h"
#include<fstream>
#include <iomanip>  
#include <algorithm>
#include <sstream>
#include <cstdlib>//thư viện để dùng system("cls")

using namespace std;
class quanlynhanvien{
    private:
    nhanvien** ds;
    int n;
    string key;
    public:
    quanlynhanvien();
    ~quanlynhanvien();
    void nhap();
    void xuat();
    void ghifile();
    void docfile();
    void timkiemtheomanv();
    void kiemtramanv();
    void addnhanvien();
    void deletenhanvien(int manv);
    void updatenhanvien(int manv);
    void lichsudangnhap();
    double tinhtongluong();
};
quanlynhanvien::quanlynhanvien(){
    ds=NULL;
    n=0;
}
quanlynhanvien::~quanlynhanvien(){
    if(ds != NULL){
        for(int i = 0; i < n; i++){
            delete ds[i];
        }
        delete[] ds;
    }
}
void quanlynhanvien::nhap() {

    cout << "----------------Nhập thông tin nhân viên----------------" << endl;
    cout << "Nhập số lượng nhân viên muốn thêm: ";
    cin >> n;
    cin.ignore();
    ds = new nhanvien*[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhập thông tin nhân viên thứ " << i + 1 << ":" << endl;
        int chucvu;
        cout << "Chọn chức vụ nhân viên(1: Lập trình viên, 2: Kiểm thử viên, 3: Kế toán, 4: Nhân viên quản lý): ";
        cin >> chucvu;
        cin.ignore();
        switch(chucvu) {
            case 1:
                ds[i] = new laptrinhvien();
                break;
            case 2:
                ds[i] = new kiemthuvien();
                break;
            case 3:
                ds[i] = new ketoan();
                break;
            case 4:
                ds[i] = new nhanvienquanly();
                break;
            default:
                cout << "Loại nhân viên không hợp lệ" << endl;
                i--;
                continue;
        }
        ds[i]->nhap();
    }
    ghifile();
}

void quanlynhanvien::xuat(){
    cout<<"-------------------------------------------------------------DANH SÁCH NHÂN VIÊN------------------------------------------------------------------" << endl;
    cout<<"+----+--------+------------------+----------+------+-------------------+---------------+-----------------+-------------------+-------------------+"<<endl;
    cout<<"| STT|  MNV   |  Tên             |Gioi tinh | Tuổi | Điạ chỉ           | Số điện thoại | Email           | Chức vụ           |Lương(Triệu đồng)  |"<<endl;
    cout<<"+----+--------+------------------+----------+------+-------------------+---------------+-----------------+-------------------+-------------------+"<<endl;
    
    for(int i=0; i<n; i++){
        cout<<"| "<<i+1<<"  | "<<left<<setw(6)<<ds[i]->getmanv()<<" | "<<left<<setw(16)<<ds[i]->getten()<<" | "<<left<<setw(8)<<(ds[i]->getgioitinh() ? "Nu" : "Nam")<<" | "<<left<<setw(4)<<ds[i]->gettuoi()<<" | "<<left<<setw(17)<<ds[i]->getdiachi()<<" | "<<left<<setw(13)<<ds[i]->getsdt()<<" | "<<left<<setw(15)<<ds[i]->getemail()<<" | "<<left<<setw(17)<<ds[i]->getchucvu()<<" | "<<left<<setw(17)<<ds[i]->tinhluong()<<" |"<<endl;
    }
    cout<<"+----+--------+------------------+----------+------+-------------------+---------------+-----------------+-------------------+-------------------+"<<endl;
}
void quanlynhanvien::ghifile() {
    ofstream file("quanlynhanvien.txt", ios::trunc);
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {    
            file << ds[i]->getmanv() << "|"
                 << ds[i]->getluongcoban() << "|"
                 << ds[i]->getten() << "|"
                 << (ds[i]->getgioitinh() ? "Nữ" : "Nam") << "|"
                 << ds[i]->gettuoi() << "|"
                 << ds[i]->getdiachi() << "|"
                 << ds[i]->getsdt() << "|"
                 << ds[i]->getemail() << "|"
                 << ds[i]->getchucvu() << "|"
                 << ds[i]->tinhluong() << "|";

            if (ds[i]->getchucvu() == "lap trinh vien") {
                laptrinhvien* ltv = (laptrinhvien*)ds[i];
                     file << ltv->getngonngulaptrinh() << "|"
                          << ltv->getsogiolamthem() << "|"
                          << ltv->getvitridev() <<"."<< endl;
            } else if (ds[i]->getchucvu() == "kiem thu vien") {
                 kiemthuvien* ktv = (kiemthuvien*)ds[i];
                 file << ktv->getchuyennganh() << "|"
                      << ktv->getsogiolamthem() << "|"
                      << ktv->getsoloiphathien() <<"."<< endl;
            } else if (ds[i]->getchucvu() == "ke toan") {
                ketoan* kt = (ketoan*)ds[i];
                file << kt->getchuyennganh() << "|"
                     << kt->getsogiolamthem() <<"."<< endl;
            } else if (ds[i]->getchucvu() == "nhan vien quan ly") {
                nhanvienquanly* nvql = (nhanvienquanly*)ds[i];

                file << nvql->getsoduanquanly() << "|"

                     << nvql->getsogiolamthem() << "|"

                     << nvql->getsoduanhoanthanh() <<"."<< endl;
            } else {
                file << endl;
            }
        }
        file.close();
    } else {
        cout << "Lỗi: không thể thêm nhân viên" << endl;
    }
}

void quanlynhanvien::docfile() {
    ifstream file("quanlynhanvien.txt");
    if (!file.is_open()) {
        cout << "Lỗi" << endl;
        return;
    }
    if (ds != NULL) {
        for (int i = 0; i < n; i++) {
            delete ds[i];
        }
        delete[] ds;
        ds = NULL;
    }
    n = 0;
    string dong;
    while (getline(file, dong)) {
        if (dong.empty()) continue;
        stringstream ss(dong);
        string manv,luongcoban, ten, gioitinh, tuoi, diachi, sdt, email, chucvu, tinhluong;
        getline(ss, manv, '|');
        getline(ss, luongcoban, '|');
        getline(ss, ten, '|');
        getline(ss, gioitinh, '|');
        getline(ss, tuoi, '|');
        getline(ss, diachi, '|');
        getline(ss, sdt, '|');
        getline(ss, email, '|');
        getline(ss, chucvu, '|');
        getline(ss, tinhluong, '|');

  nhanvien* nv = NULL;
        if(chucvu == "lap trinh vien") {
            laptrinhvien* ltv = new laptrinhvien();
            string ngonngulaptrinh, sogiolamthem, vitridev;
            getline(ss, ngonngulaptrinh, '|');
            getline(ss, sogiolamthem, '|');
            getline(ss, vitridev,'.'); 
            ltv->setngonngulaptrinh(ngonngulaptrinh);
            ltv->setsogiolamthem(stoi(sogiolamthem));
            ltv->setvitridev(vitridev);
            nv = ltv;
        }
         else if (chucvu == "kiem thu vien") {

            string chuyennganh, sogiolamthem, soloiphathien;
            getline(ss, chuyennganh, '|');
            getline(ss, sogiolamthem, '|');
            getline(ss, soloiphathien,'.');
            kiemthuvien* ktv = new kiemthuvien();
            ktv->setchuyennganh(chuyennganh);
            ktv->setsogiolamthem(stoi(sogiolamthem));
            ktv->setsoloiphathien(stoi(soloiphathien));
            nv = ktv;
         }

         else if (chucvu == "ke toan") {
            string chuyennganh, sogiolamthem;
            getline(ss, chuyennganh,'|');
            getline(ss, sogiolamthem,'.');
            ketoan* kt = new ketoan();
            kt->setchuyennganh(chuyennganh);
            kt->setsogiolamthem(stoi(sogiolamthem));
            nv = kt;
        } else if (chucvu == "nhan vien quan ly") {
            string soduanquanly, sogiolamthem, soduanhoanthanh;
            getline(ss, soduanquanly, '|');
            getline(ss, sogiolamthem, '|');
            getline(ss, soduanhoanthanh,'.');
            nhanvienquanly* nvql = new nhanvienquanly();
            nvql->setsoduanquanly(stoi(soduanquanly));
            nvql->setsogiolamthem(stoi(sogiolamthem));
            nvql->setsoduanhoanthanh(stoi(soduanhoanthanh));
            nv = nvql;
        }else{
            cout << "Loi: Loai chuc vu khong hop le trong file!" << endl;
            continue;
        }
        
        int ma = stoi(manv);
        double luongcb = stoll(luongcoban);
        bool gt = (gioitinh == "Nữ" || gioitinh == "Nu" || gioitinh == "1") ? true : false;
        int tu = stoi(tuoi);

        nv->setmanv(ma);
        nv->setluongcoban(luongcb);
        nv->setten(ten);
        nv->setgioitinh(gt);
        nv->settuoi(tu);
        nv->setdiachi(diachi);
        nv->setsdt(sdt);
        nv->setemail(email);
        nv->setchucvu(chucvu);

        nhanvien** temp = new nhanvien*[n + 1];
        for (int i = 0; i < n; i++) {
            temp[i] = ds[i];
        }
        temp[n] = nv;
        delete[] ds; 
        ds = temp;   
        n++;         
    }
    file.close();
}
int tam;
void quanlynhanvien::timkiemtheomanv(){
    tam=0;
    int manv;
                 while (true) {
                cout << "Nhập mã nhân viên của bạn: ";
                if (cin >> manv && manv > 0 && to_string(manv).length() == 6) {
                cin.ignore(); 
                break;
              } else {
              cout << "Lỗi"<<endl; 
               }
             }
    for(int i=0; i<n; i++){
        if(ds[i]->getmanv()==manv){
            system("cls");
            cout<<"Thông tin nhân viên có mã số "<<manv<<":"<<endl;
            cout<<"+--------------------------------------------------------------THÔNG TIN CHUNG NHÂN VIÊN-----------------------------------------------------------------------------------+" << endl;
            cout<<"| STT| Tên nhân viên             |   Giới tính     | Tuổi  | Địa chỉ                 | Số điện thoại   | Email           | Chức vụ                 |Lương(Triệu đồng)      |"<<endl;
            cout<<"+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
            cout<<"| 1  | "<<left<<setw(25)<<ds[i]->getten()<<" | "<<left<<setw(15)<<(ds[i]->getgioitinh() ? "Nữ" : "Nam")<<" | "<<left<<setw(7)<<ds[i]->gettuoi()<<" | "<<left<<setw(23)<<ds[i]->getdiachi()<<" | "<<left<<setw(15)<<ds[i]->getsdt()<<" | "<<left<<setw(15)<<ds[i]->getemail()<<" | "<<left<<setw(23)<<ds[i]->getchucvu()<<" | "<<left<<setw(21)<<ds[i]->tinhluong()<<" |"<<endl;
            cout<<"+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
            cout<<"+-----------------------------------------------------------THÔNG TIN CHI TIẾT CỦA NHÂN VIÊN-------------------------------------------------------------------------------+"<<endl;
            ds[i]->xuat();
            return;
        }
    }
    cout<<"Không tìm thấy nhân viên có mã số "<<manv<<endl;
    tam++;
}
void quanlynhanvien::kiemtramanv(){
    tam=0;
    int manv;
                 while (true) {
                cout << "Nhập mã nhân viên của bạn: ";
                if (cin >> manv && manv > 0 && to_string(manv).length() == 6) {
                cin.ignore(); 
                break;
              } else {
              cout << "Loi: Ma nhan vien phai la so nguyen duong va co 6 chu so. Vui long nhap lai!\n"; 
               }
             }
    for(int i=0; i<n; i++){
        if(ds[i]->getmanv()==manv){
            return;
        }
    }
    cout<<"Không tìm thấy nhân viên có mã số "<<manv<<endl;
    tam++;
}
void quanlynhanvien::addnhanvien(){
    int loai;
    cout<<"Chọn vị trí nhân viên (1: Lập trình viên, 2: Kiểm thử viên, 3: Kế toán, 4: Nhân viên quản lý nhân sự): ";
    cin>>loai;
    cin.ignore();
    nhanvien *nv=NULL;
    switch(loai) {
        case 1: nv = new laptrinhvien(); break;
        case 2: nv = new kiemthuvien(); break;
        case 3: nv = new ketoan(); break;
        case 4: nv = new nhanvienquanly(); break;
        default:
            cout << "LỰA CHỌN CỦA BẠN KHÔNG HỢP LỆ" << endl;
            return;
    }
    nv->nhap();
    nhanvien** temp=new nhanvien*[n+1];
    for(int i=0; i<n; i++){
        temp[i]=ds[i];
    }
    temp[n]=nv;
    delete[] ds;
    ds=temp;
    n++;
    ghifile();
}
void quanlynhanvien::deletenhanvien(int manv){
    int a = -1;
    for(int i = 0; i < n; i++){
        if(ds[i]->getmanv() == manv){
            a = i;
            break;
        }
    }
    if(a == -1){
        cout << "Không tìm thấy nhân viên có mã số " << manv << endl;
        return;
    }
    delete ds[a];
    if (n == 1) {
        delete[] ds;
        ds = NULL;
        n = 0;
    } else {
        nhanvien** temp = new nhanvien*[n - 1];
        for(int i = 0; i < a; i++){
            temp[i] = ds[i];
        }
        for(int i = a; i < n - 1; i++){
            temp[i] = ds[i + 1];
        }
        delete[] ds; 
        ds = temp;   
        n--;        
    }
    ghifile();
    cout << "Đã xóa nhân viên có mã số " << manv << " khỏi danh sách" << endl;
}
void quanlynhanvien::updatenhanvien(int manv){
    int a=-1;
    for(int i=0; i<n; i++){
        if(ds[i]->getmanv()==manv){
            a=i;
            break;
        }
    }
    if(a==-1){
        cout<<"Không tìm thấy nhân viên có mã"<<manv<<endl;
        return;
    }
    ds[a]->nhap();
    ghifile();
}
void quanlynhanvien::lichsudangnhap(){
    docfilelichsu();
}
double quanlynhanvien::tinhtongluong(){
    double tongluong=0;
    for(int i=0; i<n; i++){
        tongluong+=ds[i]->tinhluong();
    }
    return tongluong;
}