/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 02 / March / 2019
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define abs(a) a = ((a<0)?a*-1:a)
long long int Extended_Euclidean(long long int a,long long int b, long long int &x,long long int &y){
    // returns Ax + By = D ( where D = gcd(a,b))
    // 2250 x 1 + 360 x -6 = 90
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long int x1, y1;
    long long int d = Extended_Euclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
bool find_any_solution(long long int a, long long int b, long long int c, long long int &x0, long long int &y0, long long int &g) {
    g = Extended_Euclidean((a), (b), x0, y0);
    if (c % g) {
        return false;
    }
    x0 *= c / g;
    y0 *= c / g;
    if(a<0) x0= -x0;
    if(b<0) y0= -y0;
    return true;
}
int main(){
    long long int n,m,a,k,a1,b1,c1,a2,b2,c2,x1,x2,y1,y2,d1,d2,g1,g2,ans1,ans2;

    while(1){
        cin >> n >> m >> a >> k;
        if(n == 0 && m == 0 && a == 0 && k == 0){
            break;
        }
        a1 = m;
        b1 = -a;
        c1 = a+k-n;
        a2 = m;
        b2 = -a;
        c2 = k-n+m;
        if(m == 0){
            if((n-a-k)%(a) == 0){
                cout << n << endl;
            }else{
                cout << "Impossible"<< endl;
            }
            continue;
        }else if(a == 0){
            cout << "Impossible" << endl;
            continue;
        }
    msg2(a1,b1,c1)
    msg2(a2,b2,c2)
        d1 = find_any_solution(a1,b1,c1,x1,y1,g1);
        d2 = find_any_solution(a2,b2,c2,x2,y2,g2);
        msg3("SOL1", x1,y1,d1)
        msg3("SOL2", x2,y2,d2)
        if(x1<0){
            //ans1 =
        }
        //x1 = abs(x1);
        //y1 = abs(y1);
        ans1 = x1*m + n;
        ans2 = y1*a + a +k;
        msg(ans1,ans2)
        if(!d1){
            cout << "Impossible"<<endl;
        }else if(ans1 >= n && ans1 >= a+k){
            cout << ans1 << endl;
        }else if(ans2 >= n && ans2 >= a+k){
            cout << ans2 << endl;
        }else{
            cout << "Impossible"<<endl;

        }
//            cout << ans << endl;
//        }else{
//            cout << "Impossible" << endl;
//        }


    }

    return 0;
}
