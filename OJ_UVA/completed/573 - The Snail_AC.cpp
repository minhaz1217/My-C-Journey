#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    double h,u,d,f,current,i,success, day;
    while(1){
        cin >> h >> u >> d >> f;
        if( !(h&&u&&d&&f)){
            break;
        }
        current = 0;
        success =0;
        day = 0;
        f = u * f/100;
        //cc(f)
        for(i=1;;i++){
            current = current + u;
            //printf("%lf %.2lf\n", current, u);
           //msg(current,(double)u)
            //msg2("1", current, ()u)
            if(current > h){
                success = 1;
                day = i;
                break;
            }
            if(u<=0){
                f = 0;
                u = 0;
            }
            u = u - f;
            current = current - d;
            //msg(current ,u )
            if(current > h){
                success = 1;
                day = i;
                break;
            }
            if(current<0){
                //cc(current)
                success = 0;
                day = i;
                break;
            }

        }
        if(success == 1){
            cout << "success on day " << day << endl;

        }else{
            cout << "failure on day " << day << endl;

        }

    }

    return 0;
}
