#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define MOD 1000000007
int main(){
    long long int sum, blockSize;
    string str;
    sum = 1;
    blockSize = 0;
    cin >> str;
    for(int i=0;str[i];i++){
        if(str[i] == 'b'){
            //msg(i,blockSize)
            sum = ((sum%MOD) * ((blockSize+1)%MOD)) % MOD;
            blockSize = 0;
        }else{
            if(str[i] == 'a'){
                blockSize++;
            }
        }
    }
    if(blockSize != 0){
        sum = ((sum%MOD) * ((blockSize+1)%MOD)) % MOD;
    }
    cout << (long long int)(sum-1)%MOD << endl;

    return 0;
}
