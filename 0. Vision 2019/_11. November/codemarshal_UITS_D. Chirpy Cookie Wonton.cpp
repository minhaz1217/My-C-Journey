/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://algo.codemarshal.org/contests/uits_iupc_19/problems/D
Date : 31 / October / 2019
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MX 11
deque<string>dq[MX];

int main(){
    long long int caseCounter = 1,n,tc,l,r,a;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string str,myStr,b,myStr2;
    cin >> tc;
    while(tc--){
            vector<string>vec;
        for(int i=1;i<=9;i++){
            dq[i].clear();
        }
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> str;
            dq[str[0]-'0'].push_back(str);
        }

        for(int i=1;i<=9;i++){
            sort(dq[i].begin(),dq[i].end());
        }
//        for(int i=1;i<=9;i++){
//            for(int j=0;j<dq[i].size();j++){
//                cout << dq[i][j] << " ";
//            }
//            cout << endl;
//
//        }
        cout << "Case " << caseCounter++ <<": ";
        string my[11] = {"0","1","2","3","4","5","6","7","8","9"};
        while(n--){
            cout << endl;
            for(int i=9;i>=1;i--){
                if(dq[i].size() >= 1){
//                    msg(dq[i].front(), dq[i].back())
                    if(dq[i].front().size() == dq[i].back().size()){
                        cout << dq[i].back();
                        dq[i].pop_back();
                        break;
                    }else if(dq[i].front().size() < dq[i].back().size()){
                        //msg(dq[i].front(), dq[i].back());
                        string temp = dq[i].back().substr(dq[i].front().size(), 1);
                        //msg("HI",temp)
                        if( temp >= my[i]){
                            cout << dq[i].back();
                            dq[i].pop_back();
                            break;
                        }else{
                            cout << dq[i].front();
                            dq[i].pop_front();
                            break;
                        }
                    }else{
                        cout << dq[i].back();
                        dq[i].pop_back();
                        break;
                    }
                }
            }
        }
        cout << endl;
//        for(int i=0;i<dq[1].size();i++){
//            cout << dq[1][i] << endl;
//        }
        //cout << "Case " << caseCounter++ << ": " << vec2[1] << endl;
    }
    return 0;
}
