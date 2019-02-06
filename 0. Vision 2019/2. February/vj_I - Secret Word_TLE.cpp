/*
Minhazul Hayat Khan
EWU
Problem Name:
Problem Link: https://vjudge.net/contest/278631#problem/I
Date : 06 / February / 2019
Comment:
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
    int tc,currFound,pos;
    string str,temp;
    cin >> tc;
    vector<int>vec[27];
    while(tc--){
        cin >> str;
        temp = str;
        reverse(temp.begin(), temp.end());
        if(temp == str){
            cout << str << endl;
            continue;
        }
        for(int i=0;i<27;i++){
            vec[i].clear();
        }
        for(int i=0;str[i];i++){
            vec[str[i] -'a'].push_back(i);
        }
        for(int i=0;i<=26;i++){
            sort(vec[i].begin(), vec[i].end());
        }
        vector<int>myVec= (vec[str[0]-'a']);
        /*
        for(int i=0;i<myVec.size();i++){
            cout << myVec[i] << " ";
        }
        cout << endl;
*/
        temp = str[0];
        for(int i=1;str[i];i++){
            currFound = 0;
            for(int j=0;j<myVec.size();j++){
                if(myVec[j] !=-1){
                    pos = lower_bound(vec[ str[i]-'a'].begin(), vec[ str[i]-'a' ].end(), myVec[j]-1 ) -vec[ str[i]-'a' ].begin();
                    //msg3(myVec[j]-1, pos, str[i]-'a', vec[ str[i]-'a' ][pos])
                    if( vec[ str[i]-'a' ][pos] == myVec[j]-1 ){
                        //cc("HELLO")
                        myVec[j] = myVec[j]-1;
                        if(currFound == 0){
                            temp += str[i];
                            currFound = 1;
                        }
                    }else{
                        myVec[j] = -1;

                    }
                }
            }
            if(currFound == 0){
                break;
            }
        }
        cout << temp << endl;
    }

    return 0;
}
