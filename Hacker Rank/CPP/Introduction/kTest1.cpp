#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int n,q,k,i,j,r,s,a[5000][5000];

    cin >> n >> q;

    for(i=0;i<n;i++){
         cin >> k;
        for(j=0;j<k;j++){
            cin >> a[i][j];
        }
    }
    for(int p=0;p<q;p++){
        cin >> r >> s;
        cout << a[r][s] << endl;
    }
	return 0;
}
