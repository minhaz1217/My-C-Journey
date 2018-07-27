#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX (1<<17)+5
int arr[MX];
int tree[4*MX];
int xorLvl;

void build(int nod, int l, int r, int lvl){
    if(l==r){
        //msg(l,r)
        xorLvl = (lvl%2);
        tree[nod] = arr[l];
        //return arr[l];
        return;
    }
    //cc(lvl)
    int left = nod*2, right = nod*2+1;
    int mid = (l+r)/ 2;
    build(left, l, mid, lvl+1);
    build(right, mid+1, r, lvl+1);

    if(lvl%2 == xorLvl){
        tree[nod] = (tree[left]^tree[right]);
    }else{
        tree[nod] = (tree[left]|tree[right]);
    }
}
void update(int nod, int l, int r, int lvl,int pos, int val){
    if(pos > r || pos < l){
        return;
    }
    if(l >= pos && r <= pos){
        //cc("HELLO")
        tree[nod] = val;
        return;
    }
    int left = nod*2, right = nod*2+1;
    int mid = (l+r)/ 2;
    update(left, l, mid, lvl+1, pos, val);
    update(right, mid+1, r, lvl+1, pos, val);

    if(lvl%2 == xorLvl){
        tree[nod] = (tree[left]^tree[right]);
    }else{
        tree[nod] = (tree[left]|tree[right]);
    }
}
int main(){
    long long int n,m,i,sum,a,b;
    //cc(MX)
    /*
    while(1){
        cin >> n >> m;
        msg("OR", (n|m))
        msg("XOR", (n^m))
        msg("AND", (n&m))
    }
    */

    scanf("%lld%lld", &n, &m);
    n = (1<<n);
    cc(n)
    for(i=1;i<=n;i++){
        cc(i)
        scanf("%lld", &arr[i]);
    }
    cc("FINISHED\n\n\n\n\n\n\n")
    build(1,1,n,1);
    /*
    for(i=1;i<=4*n;i++){
        cout << tree[i] << " ";
        //cout << arr[i] << " ";
    }
    cout <<endl;
    */
    for(i=1;i<=m;i++){
        scanf("%lld%lld", &a, &b);
        update(1,1,n,1,a,b);
        printf("%d\n", tree[1]);
        //cc(tree[1])
    }
    return 0;
}
