#include<iostream>
using namespace std;
struct Time{
    int hours, minutes, seconds;
};
int main(){
    Time t1;
    char extra;
    cout << "Enter time(hh:mm:ss): ";
    cin >> t1.hours >> extra >> t1.minutes >> extra >> t1.seconds;
    cout << (t1.hours*3600 + t1.minutes * 60 + t1.seconds) << endl;
	return 0;
}
