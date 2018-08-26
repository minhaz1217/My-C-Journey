// funny liner 10^6 comparison

#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){

    while(1){
        long long int n,left, mn, right;
        char c;
        string str;
        cin >> n ;
        if(n == 0){
            break;
        }
        cin >> str;

        mn = INT_MAX;
        left = -1;
        right = -1;
        for(long long int i=0;str[i];i++){
            c = str[i];
            if(c == 'Z'){
                mn = 0;
                break;
            }
            if(c == 'R'){
                right = i;

                if(left != -1){
                    mn = min(mn , abs(i-left));
                    //right = i;
                }
            }else if(c == 'D'){
                left = i;

                if(right != -1){
                    mn = min(mn , abs(i-right));
                    //left = i;
                }
            }
        }
        cout << mn << endl;
    }
    return 0;
}
