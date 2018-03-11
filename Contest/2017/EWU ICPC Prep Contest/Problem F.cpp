#include<iostream>
using namespace std;
int main(){
    int tc,maxDay,startDay,vacationDay=0,i;
    string mon, day;
    cin >> tc;
    while(tc--){
        cin >> mon >> day;
        // cout << mon << ":" << day << endl;
        if(mon == "JAN" || mon == "MAR" || mon == "MAY" || mon == "JUL" || mon == "AUG" || mon == "OCT" || mon == "DEC"){
            maxDay = 31;
        }else if(mon == "FEB"){
            maxDay = 28;
        }else{
            maxDay = 30;
        }
        if(day == "SUN"){
            startDay = 1;
        }else if(day == "MON"){
            startDay = 2;
        }else if(day == "TUE"){
            startDay = 3;
        }else if(day == "WED"){
            startDay = 4;
        }else if(day == "THU"){
            startDay = 5;
        }else if(day == "FRI"){
            startDay = 6;
        }else if(day == "SAT"){
            startDay = 7;
        }
        vacationDay = 0;
        for(i = 1;i<= maxDay;i++){
            if(startDay == 6 || startDay == 7){
                vacationDay++;
            }
            startDay++;
            if(startDay > 7){
                startDay = 1;
            }
        }
        cout << vacationDay << endl;
    }
	return 0;
}
