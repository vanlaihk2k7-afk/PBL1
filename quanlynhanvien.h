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
    void timkiemtheomanv(int manv);
    void addnhanvien();
    void deletenhanvien(int manv);
    void updatenhanvien(int manv);
    void sapxeptheoten();
    void lichsudangnhap();
    long long tinhtongluong();
    void tinhtongnhanvien();
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

    cout << "----------------Nhap thong tin nhan vien----------------" << endl;
    cout << "Nhap so luong nhan vien muon them: ";
    cin >> n;
    cin.ignore();
    ds = new nhanvien*[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
        int chucvu;
        cout << "Chon chuc vu nhan vien (1: Lap trinh vien, 2: Kiem thu vien, 3: Ke toan, 4: Nhan vien quan ly): ";
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
                cout << "Loai nhan vien khong hop le!" << endl;
                i--;
                continue;
        }
        ds[i]->nhap();
    }
    ghifile();
}

void quanlynhanvien::xuat(){
    cout<<"----------------------------------------------------------Danh sach nhan vien----------------------------------------------------------------+" << endl;
    cout<<"+----+--------+-------------+-------------+-------+-------------------+---------------+-----------------+----------------+--------------------"<<endl;
    cout<<"| STT|  MNV   |  Ten        |  Gioi tinh  | Tuoi  | Dia chi           | So dien thoai | Email           | Chuc vu        |Luong              |"<<endl;
    cout<<"+----+--------+-------------+-------------+-------+-------------------+---------------+-----------------+----------------+--------------------"<<endl;
    
    for(int i=0; i<n; i++){
        cout<<"| "<<i+1<<"  | "<<left<<setw(6)<<ds[i]->getmanv()<<" | "<<left<<setw(11)<<ds[i]->getten()<<" | "<<left<<setw(11)<<(ds[i]->getgioitinh() ? "Nữ" : "Nam")<<" | "<<left<<setw(5)<<ds[i]->gettuoi()<<" | "<<left<<setw(17)<<ds[i]->getdiachi()<<" | "<<left<<setw(13)<<ds[i]->getsdt()<<" | "<<left<<setw(15)<<ds[i]->getemail()<<" | "<<left<<setw(14)<<ds[i]->getchucvu()<<" | "<<left<<setw(17)<<ds[i]->tinhluong()<<" |"<<endl;
    }
    cout<<"+----+--------+-------------+-------------+-------+-------------------+---------------+-----------------+----------------+-------------------+"<<endl;
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
        cout << "=> Da cap nhat toan bo danh sach vao file quanlynhanvien.txt!" << endl;
    } else {
        cout << "Loi: Khong the mo file de ghi!" << endl;
    }
}

void quanlynhanvien::docfile() {
    ifstream file("quanlynhanvien.txt");
    if (!file.is_open()) {
        cout << "Loi: Khong the mo file hoac file chua ton tai!" << endl;
        return;
    }
    if (ds != NULL) {
        for (int i = 0; i < n; i++) {
            delete ds[i];
        }
        delete[] ds;
        ds = NULL;
    }
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
        // if(chucvu == "lap trinh vien") {
        //     laptrinhvien* ltv = new laptrinhvien();
        //     string ngonngulaptrinh, sogiolamthem, vitridev;
        //     getline(ss, ngonngulaptrinh, '|');
        //     getline(ss, sogiolamthem, '|');
        //     getline(ss, vitridev,'.'); 
        //     ltv->setngonngulaptrinh(ngonngulaptrinh);
        //     ltv->setsogiolamthem(stoi(sogiolamthem));
        //     ltv->setvitridev(vitridev);
        //     nv = ltv;
        // } else if (chucvu == "kiem thu vien") {

        //     string chuyennganh, sogiolamthem, soloiphathien;
        //     getline(ss, chuyennganh, '|');
        //     getline(ss, sogiolamthem, '|');
        //     getline(ss, soloiphathien,'.');
        //     kiemthuvien* ktv = new kiemthuvien();
        //     ktv->setchuyennganh(chuyennganh);
        //     ktv->setsogiolamthem(stoi(sogiolamthem));
        //     ktv->setsoloiphathien(stoi(soloiphathien));
        //     nv = ktv;

        // } else if (chucvu == "ke toan") {
        //     string chuyennganh, sogiolamthem;
        //     getline(ss, chuyennganh,'|');
        //     getline(ss, sogiolamthem,'.');
        //     ketoan* kt = new ketoan();
        //     kt->setchuyennganh(chuyennganh);
        //     kt->setsogiolamthem(stoi(sogiolamthem));
        //     nv = kt;
        // } else if (chucvu == "nhan vien quan ly") {
        //     string soduanquanly, sogiolamthem, soduanhoanthanh;
        //     getline(ss, soduanquanly, '|');
        //     getline(ss, sogiolamthem, '|');
        //     getline(ss, soduanhoanthanh,'.');
        //     nhanvienquanly* nvql = new nhanvienquanly();
        //     nvql->setsoduanquanly(stoi(soduanquanly));
        //     nvql->setsogiolamthem(stoi(sogiolamthem));
        //     nvql->setsoduanhoanthanh(stoi(soduanhoanthanh));
        //     nv = nvql;
        // }else{
        //     cout << "Loi: Loai chuc vu khong hop le trong file!" << endl;
        //     continue;
        // }
        

        int ma = stoi(manv);
        long long luongcb = stoll(luongcoban);
        bool gt = (gioitinh == "Nữ" || gioitinh == "Nu" || gioitinh == "1") ? true : false;
        int tu = stoi(tuoi);


        if (chucvu == "lap trinh vien") {
            nv = new laptrinhvien();

        } else if (chucvu == "kiem thu vien") {
            nv = new kiemthuvien();

        } else if (chucvu == "ke toan") {
            nv = new ketoan();

        } else if (chucvu == "nhan vien quan ly") {
            nv = new nhanvienquanly();
        } else {
            continue;

        }

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

    cout << "=> Doc file thanh cong! Da nap " << n << " nhan vien vao chuong trinh." << endl;

}

void quanlynhanvien::timkiemtheomanv(int manv){
    docfile();
    for(int i=0; i<n; i++){
        if(ds[i]->getmanv()==manv){
            cout<<"Thong tin nhan vien co ma nhan vien "<<manv<<":"<<endl;
            cout<<"----------------------------------------------------------Thong tin nhan vien------------------------------------------------------------------------------------" << endl;
            cout<<"| STT| Ten nhan vien        |   Gioi tinh     | Tuoi  | Dia chi                 | So dien thoai   | Email           | Chuc vu                 |Luong(Trieu dong) |"<<endl;
            cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"| 1  | "<<left<<setw(20)<<ds[i]->getten()<<" | "<<left<<setw(15)<<(ds[i]->getgioitinh() ? "Nữ" : "Nam")<<" | "<<left<<setw(5)<<ds[i]->gettuoi()<<" | "<<left<<setw(23)<<ds[i]->getdiachi()<<" | "<<left<<setw(15)<<ds[i]->getsdt()<<" | "<<left<<setw(15)<<ds[i]->getemail()<<" | "<<left<<setw(23)<<ds[i]->getchucvu()<<" | "<<left<<setw(16)<<ds[i]->tinhluong()<<" |"<<endl;
            cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            ds[i]->xuat();
            return;
        }
    }
    cout<<"Khong tim thay nhan vien co ma nhan vien "<<manv<<endl;
}
void quanlynhanvien::addnhanvien(){
    int loai;
    cout<<"Chon chuc vu nhan vien (1: Lap trinh vien, 2: Kiem thu vien, 3: Ke toan, 4: Nhan vien quan ly): ";
    cin>>loai;
    cin.ignore();
    nhanvien *nv=NULL;
    switch(loai) {
        case 1: nv = new laptrinhvien(); break;
        case 2: nv = new kiemthuvien(); break;
        case 3: nv = new ketoan(); break;
        case 4: nv = new nhanvienquanly(); break;
        default:
            cout << "=> Lua chon khong hop le!" << endl;
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
    docfile();
    int a = -1;
    for(int i = 0; i < n; i++){
        if(ds[i]->getmanv() == manv){
            a = i;
            break;
        }
    }
    if(a == -1){
        cout << "Khong tim thay nhan vien co ma " << manv << endl;
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
    cout << "=> Da xoa nhan vien co ma " << manv << " thanh con!" << endl;
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
        cout<<"Khong tim thay nhan vien co ma "<<manv<<endl;
        return;
    }
    ds[a]->nhap();
    ghifile();
}
void quanlynhanvien::sapxeptheoten(){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(ds[j]->getten()>ds[j+1]->getten()){
                swap(ds[j], ds[j+1]);
            }
        }
    }
}
void quanlynhanvien::lichsudangnhap(){
    docfilelichsu();
}
long long quanlynhanvien::tinhtongluong(){
    long long tongluong=0;
    for(int i=0; i<n; i++){
        tongluong+=ds[i]->tinhluong();
    }
    return tongluong;
}
void quanlynhanvien::tinhtongnhanvien(){
    cout<<nhanvien::gettongnv();
}
