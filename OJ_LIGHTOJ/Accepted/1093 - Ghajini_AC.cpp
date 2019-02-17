#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

#define M 100400
int treeMax[M*3], treeMin[M*3], arr[M];
//int prop[M*3];

void init(int nod, int b, int e){
    if(b == e){
        //msg(nod,arr[b])
        treeMax[nod] = arr[b];
        treeMin[nod] = arr[b];
        return;
    }
    int left = nod*2, right = (nod*2)+1, mid = (b+e)/2;
    init(left, b , mid);
    init(right, mid+1, e);

    treeMax[nod] = max(treeMax[left], treeMax[right]);
    treeMin[nod] = min(treeMin[left], treeMin[right]);
    //tree[nod] = tree[left] + tree[right];
}

int queryMin(int nod, int b, int e, int i, int j){
    if(i>e || j < b){
        return INT_MAX;
    }
    if(b >= i && e<=j){
        return treeMin[nod];
    }
    int left = nod*2, right = nod*2 + 1, mid = (b+e)/2;
    int p1 = queryMin(left, b,mid,i,j);
    int p2 = queryMin(right, mid+1, e, i,j);
    return min(p1,p2);
}
int queryMax(int nod, int b, int e, int i, int j){
    if(i>e || j < b){
        return INT_MIN;
    }
    if(b >= i && e<=j){
        return treeMax[nod];
    }
    int left = nod*2, right = nod*2 + 1, mid = (b+e)/2;
    int p1 = queryMax(left, b,mid,i,j);
    int p2 = queryMax(right, mid+1, e, i,j);
    return max(p1,p2);
}



int main(){
    int tc,n,d,my,myMax,myMin,caseCounter=1;
    cin >> tc;
    while(tc--){
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> arr[i];
        }
        init(1,1,n);
/*
        for(int i=0;i<=n*2+1;i++){
            cout << treeMax[i] << " ";
        }
        cout << endl;
        for(int i=0;i<=n*2+1;i++){
            cout << treeMin[i] << " ";
        }
        cout << endl;*/
        my = INT_MIN;
        d--;
        for(int i=1;i<=n-d+1;i++){
            myMax = queryMax(1,1,n,i,i+d);
            myMin = queryMin(1,1,n,i,i+d);
            //msg3(i,i+d, myMax,myMin)
            my = max(my, myMax- myMin);
        }
        cout << "Case " << caseCounter++ << ": " << my << endl;
        //msg("ANS", my)
    }
    return 0;
}
