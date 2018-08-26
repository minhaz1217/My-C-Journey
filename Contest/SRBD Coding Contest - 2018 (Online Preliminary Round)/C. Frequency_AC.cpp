#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int tc;
    cin >> tc;
    while(tc--){
        long long int n,q,sz,sum,a;
        char c;
        string str,myStr,temp ;
        vector<string>palin;
        cin >> n >> q;
        cin >> str;
        sz = str.size();
        for(int i=1;i<sz;i++){
            for(int j=0;j<=sz-i;j++){
                myStr = str.substr(j, i);
                temp = myStr;
                reverse(myStr.begin(), myStr.end());
                if(myStr == temp){
                    palin.push_back(temp);
                    //cc(temp)
                }
                //cout << myStr << endl;
            }
        }
        sort(palin.begin(), palin.end());
        for(int i=0;i<q;i++){
            cin >> a >> c;
            sum  =0;
            for(int j=0;j<palin[a-1].size();j++){
                if(palin[a-1][j] == c){
                    sum++;
                }
            }
            cout << sum << endl;
        }
    }

    return 0;
}
