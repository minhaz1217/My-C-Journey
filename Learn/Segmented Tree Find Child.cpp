#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;



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

    int n,k;
    cin >> n;
    cin >> k;
    // (2*n - 1) - (n+1)
    cout << findChildRepresent(n,k) << endl;

    return 0;
}
