//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    string str;
    int n,m,a,x,y,flag,i;
    char dir;
    while(cin >> n >> m){
        x = 0;
        y = 0;
        dir = 'r';
        flag = 1;
        for(i=0;i<m;i++){
            cin >> str >> a;
            if(flag == 0){
                continue;
            }
            if(str == "MOVE"){
                if(dir == 'r'){
                    x += a;
                }else if(dir == 'l'){
                    x-=a;
                }else if(dir == 'u'){
                    y += a;
                }else{
                    y -= a;
                }
            }else{
                if(a == 0){
                    if(dir == 'r'){
                        dir = 'u';
                    }else if(dir == 'l'){
                        dir = 'd';
                    }else if(dir == 'u'){
                        dir = 'l';
                    }else{
                        dir = 'r';
                    }
                }else{
                    if(dir == 'r'){
                        dir = 'd';
                    }else if(dir == 'l'){
                        dir = 'u';
                    }else if(dir == 'u'){
                        dir = 'r';
                    }else{
                        dir = 'l';
                    }
                }
            }
            if(x < 0 || y <0 || x > n || y > n){
                flag = 0;
            }
        }
        if(flag == 0){
            cout << -1 << endl;
        }else{
            cout << x << " " << y << endl;
        }
    }

    return 0;
}
