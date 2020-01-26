/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/352689#problem/B
Date : 25 / January / 2020
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

void mo_remove(int idx);  // TODO: remove value at idx from data structure
void mo_add(int idx);     // TODO: add value at idx from data structure
long long int mo_answer(int);  // TODO: extract the current answer of the data structure

long long int block_size,n,m,u,a,b,v,p,k;
map<long long int, long long int > mp;
vector<long long int> vec;

struct Query {
    int l, r,v,p, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};
vector<Query> query;
bool cmp(Query p, Query q) {
    if (p.l / block_size != q.l / block_size)
        return p < q;
    return (p.l / block_size & 1) ? (p.r < q.r) : (p.r > q.r);
}
vector<long long int> mo_s_algorithm(vector<Query> queries) {
    vector<long long int> answers(queries.size());
    sort(queries.begin(), queries.end(),cmp);

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            mo_add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            mo_add(cur_r);
        }
        while (cur_l < q.l) {
            mo_remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            mo_remove(cur_r);
            cur_r--;
        }
        k = mo_answer(q.v);
        vec[q.p] =  u*k/( q.r-q.l+1 ) ;
    }
    //return answers;
}
void mo_add(int id){
    long long int x = vec[id];
    if(mp.find(x) == mp.end()){
        mp[x] = 1;
    }else{
        mp[x]++;
    }
}
void mo_remove(int id){
    mp[vec[id]]--;
}
long long int mo_answer(int x){
    long long int ans = 0;
    for(auto it: mp){
        if(it.first >= x){
            return ans;
        }
        ans += it.second;
    }
    return ans;
}
int main(){
    _INIT;
    cin >> n >> m >> u;
    block_size = sqrt(n)+1;
    vec.push_back(0);
    while(n--){
        cin >> a;
        vec.push_back(a);
    }
    for(int i=0;i<m;i++){
        cin >> a >> b >>v >> p;
        Query q;
        q.l = a;
        q.r = b;
        q.idx = i;
        q.v =v;
        q.p =p;
        query.push_back(q);
    }
    vector<long long int> ans;
    ans = mo_s_algorithm(query);
    for(int i=1;i<vec.size();i++){
        cout << vec[i] << endl;
    }
    return 0;
}
