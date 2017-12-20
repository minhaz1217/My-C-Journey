#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    cin >> n >> m >> k;
    int mat[n+4][m+4];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    cin >> y1 >> x1;

    queue< pair<int, int> > q;
    q.push(pair<int, int>(y1, x1) );
    while(!q.empty()){
        y = q.front().first();
        x = q.front().second();
    }


    return 0;
}
