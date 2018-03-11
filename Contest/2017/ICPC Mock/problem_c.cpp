#include<stdio.h>
int main(){
    int tc, i,j,n,counter=0,x;
    scanf("%d", &tc);
    while(tc--){
        counter = 0;
        scanf("%d", &n);
        for(i=1;i<=n/2;i++){
            for(j=1;j<=i;j++){
                x = i+j;
                if(x >= (n -x) && x < n && (n-x)>= i ){
                   counter++;
                }
            }
        }
        printf("%d\n", counter);
    }
	return 0;
}
