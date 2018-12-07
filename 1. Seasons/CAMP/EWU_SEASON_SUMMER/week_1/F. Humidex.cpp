#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    double t=0,d=0, hum,h=0, e=0,ex, inputCounter = 0;
    char c;
    while(1){
        cin >> c;
        if(c == 'E'){
            break;
        }else if(c == 'T'){
            cin >> t;
            inputCounter++;
        }else if(c == 'D'){
            cin >> d;
            inputCounter++;
        }

        if(t != 0 && d != 0){
            //cout << "HI" << t << " : " << d << endl;
            ex = 5417.7530 * ( (1/273.16) - (1/(d+273.16)) );
            e = 6.11 * exp(ex);
            h = 0.5555 * (e-10.0);
            hum = t + h;

            printf("T %.1lf D %.1lf H %.1lf\n", t,d,hum);
            t = 0;
            d = 0;
        }
        //cout << t << ": " << d << endl;

    }

    return 0;
}
