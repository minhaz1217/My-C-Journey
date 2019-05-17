#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

vector<int>arr;
int m = 3;
void sliding_minimum_range_query(){
    int val;
    deque<pair<int,int> >dq;
    vector<int>res;
    for(int i=0;i<arr.size();i++){
        val = arr[i];
        while(!dq.empty() && dq.front().first <= val){
            //msg2("POP1", dq.front().first, dq.front().second)
            dq.pop_front();
        }
        dq.push_front(make_pair(val, i));
        while(!dq.empty() && dq.back().second <= i-m){
            //msg2("POP1", dq.back().first, dq.back().second)

            dq.pop_back();
        }
        if(i>= m-1){
            cout << dq.back().first << endl;
            res.push_back(dq.back().first);
        }
    }


}


int main(){
    arr.push_back(10);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(9);
    arr.push_back(6);
    arr.push_back(4);
    sliding_minimum_range_query();
    return 0;
}
