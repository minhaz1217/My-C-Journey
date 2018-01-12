#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define SIEVE 1000005
#define ARR 10008
bool prime[SIEVE] = {1};
int arr[ARR];
int tree[ARR*3];
int prop[ARR*3];
void sieve(){
    int i,j, root = sqrt(SIEVE);
    for(i=0;i<SIEVE;i++){
        prime[i] = 1;
    }
    for(i=2;i<=root;i++){
        if(prime[i] == 1){
            for(j=2;i*j<=SIEVE;j++){
                prime[i*j] = 0;
            }
        }
    }
}
void build(int nod, int l, int r){
    if(l == r){
        if(prime[l] == 1){
            tree[nod] = 1;
        }else{
            tree[nod] = 0;
        }
        return;
    }
    int left = nod*2,
    right = nod*2 + 1,
    mid = (l+r) / 2;
    build(left, l, mid);
    build(right, mid+1, r);
    tree[nod] = tree[left] + tree[right];
    return;
}
int query(int nod, int l, int r, int Lq, int Rq){
    if(Lq > r || Rq < l){
        return 0;
    }
    if(l >= Lq && r <= Rq){
        return tree[nod];
    }
    int left = nod * 2,
    right = nod*2 + 1,
    mid = (l+r)/2;
    if(prop[nod]){
        tree[left] += (mid-l+1) *prop[nod];
        tree[right] += (r - mid)*prop[nod];
        prop[left] += prop[nod];
        prop[right] += prop[nod];
        prop[nod] = 0;
    }
    int p1 = query(left, l, mid, Lq, Rq);
    int p2 = query(left, mid+1, r, Lq, Rq);
    return p1+p2;
}
void update(int nod, int l, int r, int Lq, int Rq, int val){
    if(Lq > r || Rq < l){
        return;
    }
    if(l >= Lq && r <= Rq){
        tree[]
    }
    int left = nod * 2,
    right = nod*2 + 1,
    mid = (l+r)/2;
    if(prop[nod]){
        tree[left] += (mid-l+1) *prop[nod];
        tree[right] += (r - mid)*prop[nod];
        prop[left] += prop[nod];
        prop[right] += prop[nod];
        prop[nod] = 0;
    }
    int p1 = query(left, l, mid, Lq, Rq);
    int p2 = query(left, mid+1, r, Lq, Rq);
    return p1+p2;
}


int main(){

    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &n, &q);
        for(i=1;i<=n;i++){
            scanf("%d", &arr[i]);
        }


    }

    return 0;
}
