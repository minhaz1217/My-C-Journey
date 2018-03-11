# include <iostream>
# include <cstdio>
using namespace std;
# define MAX 100005
int a[MAX];
int tree[4 * MAX];

void build(int node, int l, int r){
    if(l == r){
        tree[node] = a[l];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[node] = tree[left] + tree[right];
}
