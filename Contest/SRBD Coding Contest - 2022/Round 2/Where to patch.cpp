/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: Where to patch
Problem Link: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-2/challenges/where-to-patch
Complexity:
Date : 30 / Aug / 2022

Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//Segment TREE
#define M 100005
pair<int,int> tree[M*3];
pair<int,int> maxTree[M*3];
int prop[M*3];
int arr[M];
int id[M];
int Q;
void init(int nod, int b, int e){
    if(b == e){
        tree[nod].first = arr[b];
        tree[nod].second = id[b];
//        msg2("INIT", arr[b], id[b])
        return;
    }
    int left = nod*2, right = (nod*2)+1, mid = (b+e)/2;
    init(left, b , mid);
    init(right, mid+1, e);


    tree[nod].first = min(tree[left].first, tree[right].first);
    if(tree[left].first == tree[right].first){
        if(tree[left].second < tree[right].second){
            tree[nod].second = tree[left].second;
        }else{
            tree[nod].second = tree[right].second;
        }
    }else{
        if(tree[left].first < tree[right].first){
            tree[nod].second = tree[left].second;
        }else{
            tree[nod].second = tree[right].second;
        }
    }
}

void update(int nod, int b, int e, int i, int j, pair<int,int> val){
    if(i > e || j < b){
        return;
    }

    if(b>=i && e<=j){
        tree[nod] = val;
        return;
    }
    int left = nod*2, right = nod*2 + 1, mid = (b+e)/2;

    update(left, b,mid,i,j,val);
    update(right, mid+1, e, i,j,val);

    tree[nod].first = min(tree[left].first, tree[right].first);
    if(tree[left].first == tree[right].first){
        if(tree[left].second < tree[right].second){
            tree[nod].second = tree[left].second;
        }else{
            tree[nod].second = tree[right].second;
        }
    }else{
        if(tree[left].first < tree[right].first){
            tree[nod].second = tree[left].second;
        }else{
            tree[nod].second = tree[right].second;
        }
    }
}

pair<int,int> selectLowestValue( pair<int,int> a, pair<int,int> b){
    int diffA = abs(a.first - Q);
    int diffB = abs(b.first - Q);
    if(diffA < diffB){
        return a;
    }else if(diffB < diffA){
        return b;
    }else{
        if(a.second < b.second){
            return a;
        }else{
            return b;
        }
    }
}
pair<int,int> query(int nod, int b, int e){
    if(b > e){
        return make_pair(INT_MAX,INT_MAX);
    }
    if(b >= e){
        return tree[nod];
    }
    int left = nod*2, right = nod*2 + 1, mid = (b+e)/2;

    pair<int,int> p1 = query(left, b,mid);
    pair<int,int> p2 = query(right, mid+1, e);
    pair<int,int> lowestOfTwo = selectLowestValue(p1, p2);
//    msg2("L@", lowestOfTwo.first, lowestOfTwo.second)
    return selectLowestValue(lowestOfTwo, tree[nod]);
}




void initMaxTree(int nod, int b, int e){
    if(b == e){
        maxTree[nod].first = arr[b];
        maxTree[nod].second = id[b];
//        msg2("INIT", arr[b], id[b])
        return;
    }
    int left = nod*2, right = (nod*2)+1, mid = (b+e)/2;
    initMaxTree(left, b , mid);
    initMaxTree(right, mid+1, e);


    maxTree[nod].first = max(maxTree[left].first, maxTree[right].first);
    if(maxTree[left].first == maxTree[right].first){
        if(maxTree[left].second < maxTree[right].second){
            maxTree[nod].second = maxTree[left].second;
        }else{
            maxTree[nod].second = maxTree[right].second;
        }
    }else{
        if(maxTree[left].first > maxTree[right].first){
            maxTree[nod].second = maxTree[left].second;
        }else{
            maxTree[nod].second = maxTree[right].second;
        }
    }
}

void updateMaxTree(int nod, int b, int e, int i, int j, pair<int,int> val){
    if(i > e || j < b){
        return;
    }

    if(b>=i && e<=j){
        maxTree[nod] = val;
        return;
    }
    int left = nod*2, right = nod*2 + 1, mid = (b+e)/2;

    updateMaxTree(left, b,mid,i,j,val);
    updateMaxTree(right, mid+1, e, i,j,val);

    maxTree[nod].first = max(maxTree[left].first, maxTree[right].first);
    if(maxTree[left].first == maxTree[right].first){
        if(maxTree[left].second < maxTree[right].second){
            maxTree[nod].second = maxTree[left].second;
        }else{
            maxTree[nod].second = maxTree[right].second;
        }
    }else{
        if(maxTree[left].first > maxTree[right].first){
            maxTree[nod].second = maxTree[left].second;
        }else{
            maxTree[nod].second = maxTree[right].second;
        }
    }
}

pair<int,int> queryMaxTree(int nod, int b, int e){
    if(b > e){
        return make_pair(INT_MAX,INT_MAX);
    }
    if(b >= e){
        return maxTree[nod];
    }
    int left = nod*2, right = nod*2 + 1, mid = (b+e)/2;

    pair<int,int> p1 = queryMaxTree(left, b,mid);
    pair<int,int> p2 = queryMaxTree(right, mid+1, e);
    pair<int,int> lowestOfTwo = selectLowestValue(p1, p2);
//    msg2("L@", lowestOfTwo.first, lowestOfTwo.second)
    return selectLowestValue(lowestOfTwo, maxTree[nod]);
}
void printTree(int b, int e){
    for(int i=b;i<=e*2;i++){
        cout << tree[i].first << " ";
    }
    cout << endl;
}
int main(){
    _INIT;
    int n,q,a,b;
    map<int,int> index;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        arr[i] = a;
        id[i] = b;
        index[b] = i;
    }
    init(1,1,n);
    initMaxTree(1,1,n);
//    printTree(1,n);
    cin >> q;
    while(q--){
        cin >> Q;
        pair<int,int> closest = query(1,1,n);
        pair<int,int> closestMax = queryMaxTree(1,1,n);
//pair<int,int> closestMax = make_pair(INT_MAX, INT_MAX);
        pair<int,int> choosen = selectLowestValue(closest, closestMax);

        cout << choosen.second << endl;
//        msg2(closest.first, closest.second, Q)
        update(1,1,n,index[choosen.second], index[choosen.second], make_pair(INT_MAX, INT_MAX));
        updateMaxTree(1,1,n,index[choosen.second], index[choosen.second], make_pair(INT_MAX, INT_MAX));

//    printTree(1,n);
    }
    return 0;
}
