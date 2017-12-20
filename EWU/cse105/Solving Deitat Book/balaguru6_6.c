
#include<stdio.h>
#include<math.h>
main(){
    double v,p=2,r=1,n=3,i,j,k,a=3;
    v = p * (pow((1+r), n));
    for(i=1;i<=a;i++){
        for(j=1;j<=a;j++){
            for(k=1;k<=a;k++){
                p=i;
                r=j;
                n=k;
                v = p * (pow((1+r), n));
                printf("%.2lf(1+%.2lf)^%.2lf = %.2lf\n", p,r,n,v);
            }
        }
    }

}
