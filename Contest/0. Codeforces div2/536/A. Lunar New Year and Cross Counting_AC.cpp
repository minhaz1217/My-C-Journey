#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int n,counter = 0;
    cin >> n;
    string str[n+2];
    str[0] ="";
    str[n+1] = "";
    for(int i=1;i<=n+2;i++){
        str[0]  += '.';
    }
    for(int i=1;i<=n;i++){
        cin >> str[i];
        str[i] = '.' + str[i] + '.';
    }
    for(int i=0;i<n+2;i++){
        str[n+1]  += '.';
    }
    counter = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(str[i][j] == 'X' && str[i-1][j-1] == 'X' && str[i-1][j+1] == 'X' && str[i+1][j-1] == 'X' && str[i+1][j+1] == 'X' ){
                counter++;
            }
        }
    }
    cout << counter << endl;
    return 0;
}
