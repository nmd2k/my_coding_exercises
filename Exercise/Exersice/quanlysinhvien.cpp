#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct sinhvien {
    string masv;
    string tensv;
    int day, month, year;
    string address;
    void addmember();
    void print();
    bool masinhvien(string _masv);
};

bool sinhvien::masinhvien(string _masv){
    if (_masv == this->masv) return true;
    return false;
}

void sinhvien::addmember() {
    string _masv, _tensv, _address;
    int _day, _month, _year;
    char gach = '/';

    getline (cin,_masv);
    getline (cin, _tensv);
    cin >> _day >> gach >> _month >> gach >> _year;
    getline (cin, _address);

    this->masv = _masv;
    this->tensv = _tensv;
    this->day = _day;
    this->month = _month;
    this->year = _year;
    this->address = _address;
}

void sinhvien::print (){
    cout << cout << "Ma sinh vien: " << this->masv << endl
         << cout << endl << "Ten sinh vien: " << this->tensv << endl
         << cout << endl << "Ngay/thang/nam sinh " << this->day << '/' << this->month << '/' << this->year << endl
         << cout << endl << "Dia chi: " << this->address << endl;
}

void themthanhvien (vector <sinhvien>& arr){
    cout << "Moi nhap du lieu sinh vien:" << endl;
    sinhvien a;
    a.addmember();
    arr.push_back(a);
}

void inradatathanhvien (vector <sinhvien>& arr){
    for (int i=0; i<arr.size(); i++){
        arr[i].print();
        cout <<endl;
    }
}

void printmenu (){
    cout << "1. Them thanh vien" << endl
         << "2. Xoa thanh vien" << endl
         << "3. In ra data cac thanh vien" << endl
         << "4. Thoat" << endl;
}

int main (){
    vector <sinhvien> arr;
    int choice = 0;
    printmenu();
    while (true){
        cin >> choice;
        if (choice == 1) {
            themthanhvien(arr);
            choice = 0;
        }
        if (choice == 3){
            inradatathanhvien (arr);
            choice = 0;
        }
        if (choice == 4) return 0;
    }

}
