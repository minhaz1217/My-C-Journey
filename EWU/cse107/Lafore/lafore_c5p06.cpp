#include<iostream>
using namespace std;
struct Time{
    int hours, minutes, seconds;
};
int timeToSec(Time t){
    return (t.hours * 3600 + t.minutes * 60 + t.seconds);
}
Time secToTime(int sec){
    Time t;
    t.hours = sec/ 3600;
    sec = sec %3600;
    t.minutes = sec/60;
    sec = sec % 60;
    t.seconds = sec;
    return t;
}
int main(){
    Time t1,t2,t3;
    char extra;
    cout << "Enter 1st time(hh:mm:ss): ";
    cin >> t1.hours >> extra >> t1.minutes >> extra >> t1.seconds;
    cout << "Enter 2nd time(hh:mm:ss): ";
    cin >> t2.hours >> extra >> t2.minutes >> extra >> t2.seconds;
    t3 = secToTime(timeToSec(t1) + timeToSec(t2));
    cout << t3.hours << ":" << t3.minutes << ":" << t3.seconds << endl;
	return 0;
}
