#include<iostream>
using namespace std;
struct Time{
    int hours, minutes, seconds;
};
int main(){
    Time t1,t2,t3;
    char extra;
    cout << "Enter 1st time(hh:mm:ss): ";
    cin >> t1.hours >> extra >> t1.minutes >> extra >> t1.seconds;
    cout << "Enter 2nd time(hh:mm:ss): ";
    cin >> t2.hours >> extra >> t2.minutes >> extra >> t2.seconds;
    t3.hours = (t1.hours*3600 + t2.hours*3600)/3600;
    t3.minutes = (t1.minutes*60 + t2.minutes*60)/60;
    t3.seconds = (t1.seconds + t2.seconds);
    cout << t3.hours << ":" << t3.minutes << ":" << t3.seconds << endl;
	return 0;
}
