#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define M 100200
unsigned long long int tree[10*M];
unsigned long long int prop[10*M];
unsigned long long int arr[M];

void init(int nod, int b, int e){
    if(b == e){
        tree[nod] = arr[b];
        return;
    }
    int left = nod*2, right = (nod*2)+1, mid = (b+e)/2;
    init(left, b , mid);
    init(right, mid+1, e);
    tree[nod] = (tree[left] ^ tree[right]);
}
int query(int nod, int b, int e, int i, int j){
    if(i>e || j < b){
        return 0;
    }
    if(b >= i && e<=j){
        return tree[nod];
    }
    int left = nod*2, right = nod*2 + 1, mid = (b+e)/2;
    int p1 = query(left, b,mid,i,j);
    int p2 = query(right, mid+1, e, i,j);
    return (p1^p2);
}
int main(){
    int n,mid;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    init(1,1,n);
    /*
    for(int i=1;i<=10;i++){
        msg(i, tree[i])
    }
    */
    int counter = 0,ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;i+j<=n;j+=2){
            if(i+j <=n){
                counter++;
            }
            mid = (i+(i+j)-1 )/ 2;
            if(query(1,1,n, i, mid) == query(1,1,n,mid+1,i+j)){
                ans++;
            }
        }
    }
    cout << ans << endl;
    /*
    return 0;



    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            if( (r-l+1) %2 == 0){
                    counter++;
                    msg(l,r)
                mid = (l+r-1 )/ 2;
                if(query(1,1,n, l, mid) == query(1,1,n,mid+1,r)){
                    //msg2("FOUND AT", l,r)
                }
            }
        }
    }
    msg("TOTAL", counter)
    */
    return 0;
}
