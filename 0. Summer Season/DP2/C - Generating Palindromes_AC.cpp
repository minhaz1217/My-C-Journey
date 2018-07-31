#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 5004
int memo[MX][MX];
string str;
int call(int l, int r){
    if(l > r){
        return 0;
    }
    //msg2(cost, str[l],str[r])

    if(memo[l][r] >0){
        return memo[l][r];
    }
    if(str[l] == str[r]){
        memo[l][r] = call(l+1, r-1);
    }else{
        memo[l][r] = 1+min(call(l+1, r), call(l,r-1));
    }
    return memo[l][r];
}


int main(){
    int n,i,counter,caseCounter = 1,j,counter2,sz;
    cin >> n;
    counter = 0;
    cin >> str;
    sz = str.length();
    for(i=0;i<sz;i++){
        for(j=0;j<sz;j++){
            memo[i][j] = -1;
        }
    }

    counter = call(0, str.length()-1);

    //cout << "Case " << caseCounter++ << ": " <<counter << endl;
    cout << counter << endl;
    return 0;
}
