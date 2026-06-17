#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include"quanlynhanvien.h"
using namespace std;
void docfilebaocao(){
    ifstream file("baocao.txt");
    if (!file.is_open()) {
        cout << "không thể mở file!" << endl;
        return;
    }
    string thuocdong(18,' ');
    string line;
    cout  <<thuocdong << "NỘI DUNG BÁO CÁO" << endl;
    cout  << "+----------------------------------------------------------+" << endl;
    while (getline(file, line)) {
        if (line.empty()) continue; 
        cout << "| " << left << setw(61) << line << " |" << endl;
    }
    cout << "+----------------------------------------------------------+" << endl;
    file.close();
}
void ghifilebaocao(quanlynhanvien &ql){
    //ql.docfile();
    string nd;
    do{
    ql.kiemtramanv();
    }while(tam>0);
    system("cls");
    cout<<"Nhập nội dung báo cáo: ";
    getline(cin,nd);
    ofstream file("baocao.txt", ios::app); 
    if (file.is_open()) {
        file << "Mã NV: " <<" "<<"- Nội dung báo cáo: "<<nd<<endl;
        file.close();
    } else {
        cout << "Không thể ghi file!" << endl;
    }
}
