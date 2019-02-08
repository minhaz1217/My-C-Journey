/*
Minhazul Hayat Khan
EWU, Bangladesh
Problem Name: 1114 - Easily Readable
Problem Link: http://lightoj.com/volume_showproblem.php?problem=1114
Date : 07 / February / 2019
Comment: Used map, the problem should be solved using trie.
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    _INIT;
    int tc,d,q,caseCounter=1,sum;
    string str,strr;
    map<string , int>mp;
    cin >> tc;
    while(tc--){
        mp.clear();
        cin >> d;
        sum =1;
        for(int i=0;i<d;i++){
            cin >> str;
            if((int)str.size()>2){
                sort(str.begin()+1, str.end()-1);
            }
            if(mp.find(str) == mp.end() ){
                mp[str] = 1;
            }else{
                mp[str]++;
            }

        }

        //cc("HELLO")
        cin >> q;
        cout << "Case " << caseCounter++ << ":" << endl;
        cin.ignore();
        //msg("Q", q)
        for(int i=0;i<q;i++){
            sum = 1;
            getline(cin, strr);
            //cc(strr)
            stringstream ss(strr);
            while(ss>>str){
                //cin >> str;
                //cc(str)
                if((int)str.size()>2){
                    sort(str.begin()+1, str.end()-1);
                }
                //qu(str);

                    sum = sum*mp[str];

            }
            cout << sum << endl;
        }

    }


    return 0;
}
