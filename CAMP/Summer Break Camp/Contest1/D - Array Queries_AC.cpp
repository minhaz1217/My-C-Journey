#include<iostream>
#include<stdio.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int a[1000000], tree[4000000], Rq, Lq, sum = 0;
void build(int nod, int l, int r){

    if(l==r){
        tree[nod] = a[l];
        return;
    }
    int left = nod*2, right = nod*2 + 1, mid = (l+r)/2;
    build(left, l, mid);
    build(right, mid+1, r);
    tree[nod] = min(tree[left] , tree[right]);
    return;
}
void findSum(int nod, int l, int r){
    if(r<Lq || Rq < l){
        return;
    }
    if(Lq <= l && r <=Rq){
        sum = min(sum, tree[nod]);
        return;
    }
    int left = nod*2, right = nod*2 + 1, mid = (l+r)/2;
    findSum(left, l, mid);
    findSum(right, mid+1, r);
}
int main(){
    int tc, i,caseCounter=1, b,q,q1,q2,n;
    scanf("%d", &tc);
    //cin >> tc;
    while(tc--){
        scanf("%d %d", &n, &q);
        //cin >> n >> q;
        for(i=1;i<=n;i++){
            scanf("%d", &b);
            //cin >> b;
            a[i] = b;
        }
        build(1,1,n);
        printf("Case %d:\n", caseCounter++);
        //cout << "Case "<< caseCounter++ << ":" << endl;
        while(q--){
            scanf("%d %d", &q1, &q2);
            //cin >> q1 >> q2;
            Lq = q1;
            Rq=q2;
            sum = 9000000;
            findSum(1, 1,n);
            printf("%d\n", sum);
            //cout << sum<< endl;
        }
    }


    return 0;
}
