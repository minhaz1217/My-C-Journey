/*
Problem Name:
Problem Link:
*/

#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a  << "  : " << b << endl;
#define msg2(a,b,c) cout << a  << " : " << b << " : " << c << endl;

int main(){
    long long n,m,a,currPlayer, reservePlayer, currPlayerRun, reservePlayerRun,run,ball,mm;
    cin >> m >> n;
    currPlayer = 1;
    reservePlayer = 2;
    currPlayerRun = 0;
    reservePlayerRun = 0;
    ball = 0;
    run = 0;
    while(m--){
        cin >> a;
        ball++;
        if(a == -1){
            mm = max(currPlayer, reservePlayer);
            currPlayer = mm+1;
            cout << currPlayerRun << " "<<  run << endl;
            currPlayerRun = 0;
        }else if(a%2 == 0){
            run +=a;
            currPlayerRun +=a;
        }else{
            run +=a;
            currPlayerRun += a;
            swap(currPlayer, reservePlayer);
            swap(currPlayerRun, reservePlayerRun);
        }
        if(ball >= n){
            ball =0;
            swap(currPlayer, reservePlayer);
            swap(currPlayerRun, reservePlayerRun);
        }
        //msg("HI", currPlayerRun)
    }
    cout << run << endl;

    return 0;
}
