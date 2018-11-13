#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

#define pi pair<int,int>
#define pii pair<int,pair<int,int> >
priority_queue<pii ,vector< pii >, greater<pii > > pq;
vector<pair<int,int> > sl;
vector<pair<int,int> > il;



int findIntersections(){

    pii e;
    pair<int,int> segE;
    while(!pq.empty()){
        e = pq.top();
        if(e.second.second == 1){
            segE = make_pair(e.first, e.second.first);
            sl.push_back(segE);
        }
    }

}
int main(){

    // point(x,y, startingPoint? or not)

    pq.push(make_pair(1,make_pair(3,1)));
    pq.push(make_pair(9,make_pair(3,1)));
    pq.push(make_pair(1,make_pair(5,1)));
    pq.push(make_pair(9,make_pair(5,1)));
    pq.push(make_pair(1,make_pair(6,1)));
    pq.push(make_pair(5,make_pair(2,1)));
    pq.push(make_pair(3,make_pair(2,1)));
    pq.push(make_pair(3,make_pair(6,1)));



    return 0;
}
