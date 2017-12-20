#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int n, q,i,a,b,j;
    cin >> n >> q;
    int *arr[n];
    for(i=0;i<n;i++){
        cin >> a;
        //int mine[a];
        arr[i] = new int [a];
        for(j=0;j<a;j++){
            cin >> b;
            arr[i][j] = b;
            //mine[j] = b;
        }
        //delete [] mine;
    }
    for(i=0;i<q;i++){
        cin >> a >> b;
        cout << arr[a][b] << endl;
    }
	return 0;
}
