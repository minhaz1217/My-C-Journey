#include<stdio.h>
main()
{
    int t,n,j,i;
    scanf("%d",&t);
    for(j=0;j<t;j++){
        scanf("%d",&n);
        for(i=0;i<=n;i++){
            printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}
