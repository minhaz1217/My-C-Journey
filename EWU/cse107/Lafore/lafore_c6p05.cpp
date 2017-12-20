#include<iostream>
using namespace std;
class Date{
private:
    int day, month, year;
public:
    void getDate(){
        char extra;
        cout << "Enter date(dd/mm/yy): ";
        cin >> day >> extra >> month >> extra >> year;
    }
    void showDate(){
        cout << day << "/" << month << "/" << year << endl;
    }
};
int main(){
    Date d1;
    d1.getDate();
    d1.showDate();

	return 0;
}
