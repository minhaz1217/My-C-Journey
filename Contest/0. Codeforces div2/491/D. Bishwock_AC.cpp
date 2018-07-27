#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

bool cf(char c){
    if(c == '0'){
        return 1;
    }else{
        return 0;
    }
}
struct bs{
    string str1, str2;
    int cost, index;
    bs(string ss1, string ss2, int ii, int cc ){
        str1 = ss1;
        str2 = ss2;
        cost = cc;
        index = ii;
    }
};

pair<string, string> mp(string a, string b){
    return make_pair(a,b);
}
int main(){
    string st1,st2,ts1,ts2;
    int i,sz,counter = 0, myCounter,index,cost;
    cin >> st1 >> st2;
    sz = st2.size();
    for(i=0;i<sz-2;i++){
        if( cf(st1[i]) && cf(st1[i+1]) && cf(st1[i+2]) &&cf( st2[i] ) && cf(st2[i+1]) && cf(st2[i+2]) ){
            st1[i] = 'X';
            st1[i+1] = 'X';
            st1[i+2] = 'X';
            st2[i+2] = 'X';
            st2[i+1] = 'X';
            st2[i] = 'X';
            counter +=2;
        }
    }
    map<pair<string, string> , int>visited;
    index = 0;
    queue<bs>q;
    q.push( bs(st1,st2, index, 0));
    visited[mp(st1,st2)] = 1;
    bs f("","",0,0);
    myCounter = INT_MIN;

    while(!q.empty()){
        f = q.front();
        string str1, str2;
        str1 = f.str1;
        str2 = f.str2;
        index = f.index;
        cost = f.cost;
        q.pop();
        //msg2(str1,index,cost)
        if(index >= sz){
            myCounter = max(myCounter, cost);
        }else{
            q.push(bs(str1,str2,index+1,cost));
        }
        for(i=index;i<sz;i++){

            if(i != sz){
                if(cf(str1[i]) && cf(str1[i+1]) && cf(str2[i])){
                    ts1 = str1;
                    ts2 = str2;
                    ts1[i] = 'X';
                    ts2[i] = 'X';
                    ts1[i+1] = 'X';
                    q.push(bs(ts1, ts2,index+1, cost+1));
                    visited[mp(ts1, ts2)] = 1;
                }
                if(cf(str1[i]) && cf(str1[i+1]) && cf(str2[i+1])){
                    ts1 = str1;
                    ts2 = str2;
                    ts1[i] = 'X';
                    ts2[i+1] = 'X';
                    ts1[i+1] = 'X';
                    q.push(bs(ts1, ts2,index+1, cost+1));
                    visited[mp(ts1, ts2)] = 1;
                }
            }
            if(cf(str1[i+1]) && cf(str2[i+1]) && cf(str2[i])){
                    ts1 = str1;
                    ts2 = str2;
                    ts1[i+1] = 'X';
                    ts2[i] = 'X';
                    ts2[i+1] = 'X';
                    q.push(bs(ts1, ts2,index+1, cost+1));
                    visited[mp(ts1, ts2)] = 1;
            }

                        if(cf(str1[i]) && cf(str2[i+1]) && cf(str2[i])){
                    ts1 = str1;
                    ts2 = str2;
                    ts1[i] = 'X';
                    ts2[i] = 'X';
                    ts2[i+1] = 'X';
                    q.push(bs(ts1, ts2,index+1, cost+1));
                    visited[mp(ts1, ts2)] = 1;
            }

        }
    }

/*
    msg(st1, st2)
    msg(counter, myCounter)
*/
cout << counter + myCounter << endl;

    return 0;
}
