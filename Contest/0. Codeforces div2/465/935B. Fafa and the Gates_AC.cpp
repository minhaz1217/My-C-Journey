#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,x,y,counter = 0,i,currKing=0;
    string str;
    cin >> n;
    cin >> str;
    x = 0;
    y = 0;

    for(i=0;str[i];i++){
        if(str[i] == 'U'){
            y += 1;
            if(currKing == 0){
                currKing = 2;
            }
        }else if(str[i] == 'R'){
            x+=1;
            if(currKing == 0){
                currKing = 1;
            }
        }
        if(x > y && currKing != 1){
            counter++;
            currKing = 1;
        }else if(y>x && currKing != 2){
            counter++;
            currKing = 2;
        }
    }
    cout << counter << endl;
    return 0;
}
