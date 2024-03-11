#include <iostream>
#include <string>
using namespace std;

class Mansi {
    int date;
    string month;
    int year;

public:
    void getdata();
    void setdata();
};

void Mansi::getdata() {
    cout << "Enter date: ";
    cin >> date;
    cout << "Enter month: ";
    cin.ignore(); // to clear the input buffer
    getline(cin, month);
    cout << "Enter year: ";
    cin >> year;
}

void Mansi::setdata() {
    cout << "Mansi's DOB is: "<<date<<"/"<<month<<"/"<<year<< endl;
    
}

int main() {
    Mansi man;
    man.getdata();
    man.setdata();
    return 0;
}