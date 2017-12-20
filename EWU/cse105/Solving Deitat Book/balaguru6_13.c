#include<stdio.h>
main(){
    double i,j,n=300000,res =1,res2 = 1,prev,now;
    for(i=1;i<=n;i++){
        prev = res2;
        for(j=1;j<=i;j++){
            res*=j;
        }
        res2 += 1/res;
        if(i!= 1 && res2 - prev <= .00001){
            break;
        }
    }
    printf("%lf", res2);

}
