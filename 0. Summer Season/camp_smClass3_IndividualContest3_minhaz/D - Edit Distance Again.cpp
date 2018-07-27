#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 104
pair<int, pair<int,int> > my(int a, int b , int c){
    return make_pair(a, make_pair(b,c));
}
int main(){
    string str;
    int p,cr, prev, curr, cost, minCost;
    pair<int, pair<int, int> > u;
    while(cin >> str){

        queue<pair<int, pair<int,int> > >q;
        if(str[0] == toupper(str[0])){
            q.push(my(1,1,0));
            q.push(my(2,1,1));
        }else{
            q.push(my(2,1,0));
            q.push(my(1,1,1));
        }
        minCost = INT_MAX;
        while(!q.empty()){
            u = q.front();

            prev = u.first;
            curr = u.second.first;
            cost = u.second.second;
           // msg2(curr, cost, prev)
            q.pop();
            if(curr >= str.length()){
                minCost = min(cost, minCost);
                continue;
            }
            if(prev == 1){
                if(str[curr] == tolower(str[curr])){
                    q.push( my(2, curr+1, cost));
                }else{
                    q.push(my(2, curr+1, cost+1));
                }
            }else if(prev == 2){
                if(str[curr] == toupper(str[curr])){
                    q.push(my(1, curr+1, cost));
                }else{
                    q.push(my(1, curr+1, cost+1));
                }
            }

        }
        cout << minCost << endl;
    }
    return 0;
}
