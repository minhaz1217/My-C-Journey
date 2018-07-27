#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int i;
    double hh,mm,h,d,c,n,nextM,nextH,cost,ch1,ch2,th;
    cin >> hh >> mm;

    th = hh;
    nextM = 0;
    for(i=mm;hh<=20;i++){
        if(i== 60){
            i=0;
            hh++;
            if(hh==20){
                break;
            }
        }
        nextM++;
    }
    //cc(nextM)
    cin >> h >> d >> c >> n;
   // cc(nextM)
    if(th >= 20){
        c = c - c*.2;
        cost = c * ceil(h/n);
    }else{
        ch1 = c*ceil(h/n);
        ch2 = (c-c*.2) *ceil((h+nextM*d)/n);
        cost = min(ch1,ch2);
    }
    printf("%.4lf\n", cost);
    //cout << cost << endl;
    return 0;
}
