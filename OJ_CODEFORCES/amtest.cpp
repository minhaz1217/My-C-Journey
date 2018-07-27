# include <bits/stdc++.h>
using namespace std;

# define mx 140000
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

long long int a[mx];
long long int tree[4 * mx];
long long int p, b;

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
    double total = r - l + 1;
    //msg2(l, r, total)
    total = log(total) / log(2);
    int check = total;
    if(check % 2 == 0){
        tree[node] = tree[left] ^ tree[right];
    }
    else{
        tree[node] = tree[left] | tree[right];
    }
}

void update(int node, int l, int r){
    if(p < l || p > r){
        return;
    }
    if(l >= p && r <= p){
        tree[node] = b;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    update(left, l, mid);
    update(right, mid + 1, r);
    double total = r - l + 1;
    total = log(total) / log(2);
    int check = total;
    if(check % 2 == 0){
        tree[node] = tree[left] ^ tree[right];
    }
    else{
        tree[node] = tree[left] | tree[right];
    }
}

int main(){
    //cout << log2(2) << endl;
    int n, m;
    scanf("%d %d", &n, &m);
    n = pow(2, n);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    for(int i = 1; i <= m; i++){
        cin >> p >> b;
        update(1, 1, n);
        printf("%d\n", tree[1]);
    }

}
