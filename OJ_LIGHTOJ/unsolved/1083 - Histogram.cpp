#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int a[1000000], tree[4000000], Rq, Lq, sum = 0,up;
int commonPart, myMax;
void build(int nod, int l, int r){

    if(l==r){
        tree[nod] = a[l];
        return;
    }
    int left = nod*2, right = nod*2 + 1, mid = (l+r)/2;
    build(left, l, mid);
    build(right, mid+1, r);
    commonPart = min(tree[left], tree[right] );
    //tree[nod] = tree[left] + tree[right];
    tree[nod] = commonPart;
    return;
}
int findChildRepresent(int n, int k){
    if(k>=n && k<=2*n-1){
        return 1;
    }else if(k>2*n-1){
        return 0;
    }
    //sum = sum+findChildRepresent(n, 2*k);

    return (findChildRepresent(n, 2*k) + findChildRepresent(n, 2*k+1));
}
int main(){
    int tc,k, arrCounter = 1, b,i, caseCounter = 1, q1,q2,q, qType, n;
    cin >> tc;
    while(tc--){
        cin >> n;
        for(i=1;i<=n;i++){
            cin >> b;
            a[i] = b;
        }
        myMax = 0;
        build(1,1,n);
        cout << "Case "<< caseCounter++ << ": ";
        myMax = 0;
        for(i=1;i<=2*n-1;i++){
            myMax = max(myMax, tree[i] * findChildRepresent(n,i));
        }
        cout << myMax << endl;


        /*
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
        */
    }


    return 0;
}
