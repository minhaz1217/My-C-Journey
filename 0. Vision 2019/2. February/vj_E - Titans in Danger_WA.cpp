#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    _INIT;
    string str,original,originalRev;
    int a,sz,counter =0,sum;
    while(cin >> str){
        sz = str.size();
        sum = 1;
        for(int i=sz;i>=1;i--){
            sum = sum*i;
        }
        //msg("SUM", sum)
        map<string ,int> mp;
        for(int i=0;i<sum;i++){
            //if(!mp[str]){
                //mp[str] = 1;
                cout << str << endl;
            //}
            //cout << str << endl;
            next_permutation(str.begin(),str.end());
        }
        cout << endl;
    }
    return 0;
}
