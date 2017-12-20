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
