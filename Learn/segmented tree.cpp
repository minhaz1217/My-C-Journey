#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int a[1000000], tree[4000000], Rq, Lq, sum = 0,up;
void build(int nod, int l, int r){

    if(l==r){
        tree[nod] = a[l];
        return;
    }
    int left = nod*2, right = nod*2 + 1, mid = (l+r)/2;
    build(left, l, mid);
    build(right, mid+1, r);
    tree[nod] = tree[left] + tree[right];
    return;
}
void findSum(int nod, int l, int r){
    if(r<Lq || l >Rq){
        return;
    }
    if(Lq <= l && r <=Rq){
        sum += tree[nod];
        return;
    }
    int left = nod*2, right = nod*2 + 1, mid = (l+r)/2;
    findSum(left, l, mid);
    findSum(right, mid+1, r);
}

void update(int nod, int l, int r){
    // here Lq is the updated index
    if(Lq < l || Lq > r){
        return;
    }
    if(l==r){
        tree[nod] = up;
        return;
    }
    int left = nod*2, right = nod*2 + 1, mid = (l+r)/2;
    update(left, l, mid);
    update(right, mid+1, r);
    tree[nod] = tree[left] + tree[right];
    return;
}
int main(){
    int tc,k, arrCounter = 1, b,i, caseCounter = 1, q1,q2,q, qType, n;
    cin >> tc;
    while(tc--){
        cin >> n >> q;
        for(i=1;i<=n;i++){
            cin >> b;
            a[i] = b;
        }
        build(1,1,n);
        cout << "Case "<< caseCounter++ << ":" << endl;
        while(q--){
            cin >> qType;
            if(qType == 1){
                cin >> q1;
                Lq = q1+1;
                cout << a[Lq] << endl;
                a[Lq] = 0;
                up = 0;
                update(1, 1, n);
            }else if(qType == 2){
                cin >> q1 >> q2;
                Lq = q1 + 1;
                a[Lq] += q2;
                up = a[Lq];
                update(1,1,n);
            }else if(qType == 3){
                cin >> q1 >> q2;
                Lq = q1 + 1;
                Rq = q2 + 1;
                sum = 0;
                findSum(1,1,n);
                cout << sum << endl;
            }
        }
    }


    return 0;
}
