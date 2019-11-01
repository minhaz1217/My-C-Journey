/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 21 / October / 2019
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

vector<pair< double, pair<double, double> > >edgelist;
vector<double>myCost;
class disjoint_set{
    vector<int>p,rt;
public:
    disjoint_set(int n){
        p.assign(n,0);
        rt.assign(n,0);
        for(int i=0;i<n;i++){
            p[i] = i;
        }
    }
    int findSet(int x){
        if(p[x] == x){
            return x;
        }else{
            p[x] = findSet(p[x]);
            return p[x];
        }
    }
    bool isSameSet(int x, int y){
        return (findSet(x) == findSet(y));
    }

    void unionSet(int x, int y){
        if(!isSameSet(x,y)){
            int a,b;
            a = findSet(x);
            b = findSet(y);
            if(rt[a] > rt[b]){
                p[b] = a;
            }else{
                p[a] = b;
                if(rt[a] == rt[b]){
                    rt[b]++;
                }
            }
        }
    }

};

double kruskal(int n){
    // if 0-index then dj start with n otherwise n+1
    double sz, mst_cost,u,v;
    disjoint_set dj(n);
    sort(edgelist.begin(), edgelist.end());
    sz = edgelist.size();
    mst_cost = 0;
    for(long long int i=0;i<sz;i++){
        u = edgelist[i].second.first;
        v = edgelist[i].second.second;
        if(!dj.isSameSet(u,v)){
            dj.unionSet(u,v);
            mst_cost += edgelist[i].first;
            //msg("COST", mst_cost)
            myCost.push_back(edgelist[i].first);
        }
    }
    return mst_cost;

}
double getDistance(pair<double, double> a, pair<double,double>b){
    return sqrt( (a.first - b.first)*(a.first - b.first) + (a.second- b.second)*(a.second- b.second) );
}
int main(){
    double n,x,y,q,v,dist;
    vector<pair<double, double> > vec;
    cin >> n;
    while(n--){
        cin >> x >> y;
        vec.push_back( {x,y} );
    }
    for(int i=0;i<vec.size();i++){
        for(int j=i+1;j<vec.size();j++){
            dist = getDistance(vec[i],vec[j]);
            //msg("DIST", dist)
            edgelist.push_back({dist, {i,j} });
        }
    }
    myCost.push_back(0);
    kruskal(vec.size()+1);
    vector<double>arr(vec.size()+4,-1);
//    for(auto it: myCost){
//        cc(it)
//    }
    cin >> q;
    while(q--){
        cin >> v;
        printf("%.9f\n", myCost[vec.size()-v]);
    }


    return 0;
}
