#include<stdio.h>
int main(){
    long int tc,n,i,j;
    scanf("%ld", &tc);
    for(i=0;i<tc;i++){
        scanf("%ld", &n);
        if(n>0){
            printf("0");
            for(j=1;j<=n;j++){
                printf(" %ld",j);
            }
            printf("\n");
        }else{
            printf("%ld",n);
            for(j=n+1;j<=0;j++){
                printf(" %ld",j);
            }
            printf("\n");
        }
    }

    return 0;
}

