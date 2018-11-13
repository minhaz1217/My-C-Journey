#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;


//Segment TREE
#define M 1000
int tree[M*3];
int prop[M*3];
int arr[M];
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
    int left = nod*2, right = nod*2 + 1, mid = (b+e)/2;
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
        //printf("%d\n", tree[nod]);
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
    arr[1] = 1;
    arr[2] = 3;
    arr[3] = 5;
    arr[4] = 2;
    arr[5] = 10;
    init(1,1,5);
    cc(query(1,1,5, 1,5));
    cc(query(1,1,5, 3,4));
    update(1,1,5,4,4,20);
    cc(query(1,1,5, 1,5));
    cc(query(1,1,5, 3,4));
    dilit(1,1,5,2);
    cc(query(1,1,5, 1,5));
/*
21
7
41
27
38
*/
    return 0;
}
