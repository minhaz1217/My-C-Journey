#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    map<string, long long int> mp;
    string str,str2,st;
    long long a,n,k,sum,flag,charCounter = 0,i;
    cin >> n >> k;
    while(n--){
        cin >> str >> a;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        mp[str] = a;
    }
    cin.ignore();
    //cout << mp[str] << endl;
    while(k--){
        sum = 0;
        while(1){
            cin >> st;
            if(mp[st]){
                sum += mp[st];

            }else if(st == "."){
                break;
            }
            charCounter++;
        }
        cout << sum << endl;
    }

    return 0;
}
