#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b  << " : " << c << endl;

int main(){
    int a,b,flag, curr,i,turn;
    cin >> a >> b;
    curr = 0000;
    flag = 0;
    for(i=1;;i++){
        if(curr > 10000){
            break;
        }
        if(i%2 == 1){
            turn = a;
        }else{
            turn = b;
        }
        if(turn == curr){
            flag = 1;
            break;
        }
        curr++;
    }
    if(flag == 0){
        cout << "no" << endl;
    }else{
        cout << "yes" << endl;
    }
    return 0;
}
