#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,n=3,factor,id,k;
    int mat[3][3] = { {2,-1,3}, {4,-2,2}, {1,1,-1} };


    for(i=0;i<n;i++){
        id = i;
        for(j=i+1;j<n;j++){
            if(fabs(mat[j][i] > fabs(mat[id][i]))){
                id=j;
            }
        }
        if(id != i){
            for(j=i;j<=n;j++){
                swap(mat[i][j], mat[id][j]);
            }
        }
        for(j=0;j<n;j++){
            if(j!= 1){
                factor = mat[j][i] / mat[i][j];
                for(k=i;k<=n;k++){
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }
    }

    return 0;
}
