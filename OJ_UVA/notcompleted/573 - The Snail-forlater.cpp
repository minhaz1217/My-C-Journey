//for later
#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    double h,u,d,f,day=0,distance=0,flag=0,prev=0,up;
    cin >> h >> u >> d >> f;
    f=f/100;
    //check(f)
    while(1){
        up = u - (prev*f);
        if(up<=0){
            day++;
            prev = 0;
            continue;
        }
        //check(up)
        distance += up - d;
        check(distance)
        prev = up;
        day++;
        if(distance >= h){
            flag =1; //climbed out
            break;
        }else if(distance <=0){
            flag = 2;
            break;
        }

    }
    cout << day-1 << ": " << flag << endl;
	return 0;
}
