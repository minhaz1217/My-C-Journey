#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,pos, l ,r,ans=0;
    cin >> n >> pos >> l >> r;
    if(l>r){
        swap(l,r);
    }
    if(pos < l){
        ans = ans+(l-pos);
        pos = l;
        ans++;
        l = 1;
        //cc("hi1")
    }
    if(pos > r){
        ans = ans + (pos - r);
        pos = r;
        ans++;
       r= n;
        //cc("hi2")
    }
    if( abs(pos-l) < abs(pos-r) ){
            //cc("!")
        if(l>1){
            ans = ans +(pos-l);
            pos = l;
            ans++;
            //cc("hi3")
        }
        if(r<n){
            //msg("HI4", ans)
            ans = ans + (r-pos);
            ans++;
            //cc("hi4")
        }
    }else{
        if(r<n){
            //msg("HI4", ans)
            ans = ans + (r-pos);
            pos = r;
            ans++;
            //cc("hi4")
        }
        if(l>1){
            ans = ans +(pos-l);
            pos = l;
            ans++;
            //cc("hi3")
        }
    }



    cout << ans << endl;

    return 0;
}
