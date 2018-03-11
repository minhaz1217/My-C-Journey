#include<stdio.h>
//#include<iostream>
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 1000004
int nod[4*MX];
int arr[MX];
int max(int a,int b){
    return (a>=b?a:b);
}
void build(int p, int l, int r){
    int left, right,mid;
    if(l==r){
        nod[p] = arr[l];
    }else{
        left = 2*p;
        right = 2*p+1;
        mid = (l+r) / 2;
        build(left, l, mid);
        build(right, mid+1, r);
        nod[p] = max(nod[left], nod[right]);
    }
}
int Query(int p, int l, int r, int i, int j){
    int left, right,mid;
    if(i>r || j<l){
        return -1;
    }
    if(l >=i && r<=j){
        return nod[p];
    }

    left = 2*p;
    right = 2*p+1;
    mid = (l+r) / 2;
    int ll = Query(left, l, mid, i,j);
    int rr = Query(right, mid+1, r, i,j);
    if(ll == -1){
        return rr;
    }
    if(rr == -1){
        return ll;
    }
    return max(rr,ll);


}
int main(){
    int n,i,j,k;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    build(1,1,n);
    for(i=1;i<=n-k+1;i++){
        printf("%d ", Query(1,1,n,i,i+k-1) );
    }
    printf("\n");



    return 0;
}
