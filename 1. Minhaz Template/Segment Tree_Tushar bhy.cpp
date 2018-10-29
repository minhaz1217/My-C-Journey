#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;


int tree[M*3];
int prop[M*3];

void init(int nod, int b, int e){
    if(b == e){
        tree[nod] = arr[b];
        return;
    }
    int left = nod*2, right = (nod*2)+1, mid = (b+e)/2;
    init(left, b , mid);
    init(right, mid+1, e);
    tree[nod] = tree[left] + tree[right];
}
void update(int nod, int b, int e, int i, int j, int val){
    if(i > e || j < b){
        return;
    }
    if(b>=i && e<=j){
        tree[nod] += (e-b+1)*val;
        prop[nod] += val;
        return;
    }
    int left = nod*2, right = nod*2 + 1, mid = (b+e)/2;
    if(prop[nod]){
        tree[left] += (mid-b+1) * prop[nod];
        tree[right] += (e-mid) * prop[nod];
        prop[left] += prop[nod];
        prop[right] += prop[nod];
        prop[nod] = 0;
    }
    update(left, b,mid,i,j,val);
    update(right, mid+1, e, i,j,val);
    tree[nod] = tree[left] + tree[right];
}
int query(int nod, int b, int e, int i, int j){
    if(i>e || j < b){
        return 0;
    }
    if(b >= i && e<=j){
        return tree[nod];
    }
    if(prop[nod]){
        tree[left] += (mid-b+1) * prop[nod];
        tree[right] += (e-mid) * prop[nod];
        prop[left] += prop[nod];
        prop[right] += prop[nod];
        prop[nod] = 0;
    }
    int p1 = query(left, b,mid,i,j);
    int p2 = query(right, mid+1, e, i,j);
    return p1+p2;
}
void dilit(int nod, int b, int e, int i){
    if(b==e){
        tree[nod] = 0;
        printf("%d\n", tid[nod]);
        return;
    }
    int left = nod*2, right = nod*2 + 1, mid = (b+e)/2;

    if(tree[left] >= i){
        dilit(left, b,mid,i);
    }else{
        dilit(right, mid+1, e, i-tree[left]);
    }
    tree[nod] = tree[left]+ tree[right];

}



int main(){


    return 0;
}
