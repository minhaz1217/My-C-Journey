/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: http://codeforces.com/contest/400/problem/A
Date : 23 / June / 2019
Comment: uncommon loop. interesting problem.
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


int main(){
    long long int tc,flag,temp;
    vector<long long int> vec;
    string str;
    cin >> tc;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(12);
    while(tc--){
        cin >> str;
//        str = "0"+str;
        vector<pair<int,int> > ans;
        for(int i=0;i<vec.size();i++){
            flag = 1;
//            cout << endl << endl << vec[i] << endl;
            for(int c=0;c<12/vec[i];c++){
                flag = 1;
                for(int r=0;r<vec[i];r++){
                    temp = c+r*12/vec[i];
//                    msg( temp, str[temp])
                    if(str[temp] != 'X'){
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1){
//                    msg("PUSHED", vec[i])
                    ans.push_back(make_pair(vec[i], 12/vec[i]));
                    break;
                }
//                cout <<flag<< endl;
            }



        }
        sort(ans.begin(),ans.end());
//        reverse(ans.begin(),ans.end());
        cout << ans.size();
        for(int i=0;i<ans.size();i++){
            cout << " " << ans[i].first << "x" << ans[i].second;
        }
        cout << endl;
    }

    return 0;
}
