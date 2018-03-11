#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 100004

typedef long long int ll;
ll tree[4*MX], arr[MX], lazy[4*MX],temp[MX];

void build(ll nod, ll l, ll r){

    if(l== r){
        tree[nod] = arr[l];
        lazy[nod] = 0;
    }
    int mid = (l+r)/2, left = 2*nod, right = 2*nod+1;

    build(left, l, mid);
    build(right, mid+1, r);

    tree[nod] = tree[left] + tree[right];
    lazy[nod] = 0;
}
void update(ll nod, ll l, ll r, ll i, ll j, ll val){

    if(i > l || j < r){
        return;
    }
    if(l >=i && r <= j){
        tree[nod] -= ((r-l +1)*val);
        lazy[nod] += val;
        return;
    }
    int mid = (l+r)/2, left = 2*nod, right = 2*nod+1;
    update(left, l, mid, i,j,val);
    update(left, mid+1, r, i,j,val);
    tree[nod] = tree[left] + tree[right] + (r-l+1)*lazy[nod];
}







int main()
{
    ll n,i;


    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    build(1,1,n+1);
    for(i=0; i<n; i++)
    {
        cin >> temp[i];
    }


    return 0;
}
