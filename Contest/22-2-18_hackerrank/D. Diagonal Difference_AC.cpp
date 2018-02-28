#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,i,j,sum1=0,sum2=0,l,r;
    cin >> n;
    int mat[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }
    for(i=0;i<n;i++){
        sum1 += mat[i][i];
    }
    l = 0;
    r = n-1;
    for(i=0;i<n;i++){
        sum2 += mat[l][r];
        l++;
        r--;
    }
    cout << abs(sum1-sum2) << endl;

    return 0;
}
