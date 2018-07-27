#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;
#define MX 200004
int a[MX];
int b[MX];
int myCount[MX];
int n,q;
int tree[4*MX+1];

void build(int nod, int l, int r){
    if(l==r){
        tree[nod] = a[l];
        return;
    }
    int left = nod*2;
    int right = nod*2 + 1;
    int mid = (l+r)/2;
    build(left, l,mid);
    build(right, mid+1, r);
    tree[nod] = tree[left]+ tree[right];
    return;
}
int Lq, Rq, sum= 0;
void findSum(int nod, int l,int r){
    if(r < Lq || Rq < l){
        return;
    }
    if(Lq <= l && r<=Rq){
        sum += tree[nod];
        return;
    }
    int left = nod*2 , right = nod*2 +1;
    int mid = (l+r)/2;
    findSum(left, l,mid);
    findSum(right, mid+1, r);
}


int main(){
    long long int n,q,i,sum1,j;
    vector<pair<long long int, long long int> >vec;
    sum1 = 0;
    cin >> n >> q;
    for(i=1;i<=n;i++){
        cin >> b[i];
        myCount[i] = 0;

    }
    sort(b+1,b+n+1);
    build(1,1,n);

    for(i=1;i<4*n;i++){
        cout << a[i] << endl;

    }

    for(i=1;i<=q;i++){
        cin >> Lq >> Rq;
        vec.push_back(make_pair(Lq, Rq));
        for(j=Lq;j<=Rq;j++){
            myCount[i]++;
        }
    }
    for(i=n;i>=1;i--){
        cc(b[i])
        myMax = 0;
        for(j=1;j<=n;j++){
            for(k=j;k<=n;k++){
                if(arr[i] > arr[j]){
                    maxPos = i;
                }
                myMax = max(myMax, max(b[j], b[k]));
            }
        }
    }




        sum = 0;
        findSum(1,1,n);
        //cc(sum)
        sum1 += sum;

    cout << sum1<< endl;

    return 0;
}
