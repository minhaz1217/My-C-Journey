#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    unsigned long long a = 0,b = 0,x = 0,y = 0,z = 0,  yellow= 0, green =0, blue=0,sum=0;
    cin >> a >> b;
    cin >> x >> y >> z;
    /*
    a = yellow cry
    b = blue cry
    x = yellow bal
    y = green ball
    z = blue ball
    */
    yellow = x * 2 + y;
    blue = y + z*3;
    if(yellow > a){
        yellow = yellow - a;
    }else{
        yellow = 0;
    }
    if(blue > b){
        blue = blue - b;
    }else{
        blue = 0;
    }
    cout << (yellow + blue )<< endl;



    return 0;
}
