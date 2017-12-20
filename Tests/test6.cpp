#include<stdio.h>
int main()
{
    char arr[10000];
    int m,n,i,j,num,count;
   while(scanf("%d",&m)!=EOF)
    {

         arr[0]=0;
         arr[1]=1;
         for(i=2;i<=m;i++)
         {
             arr[i]=arr[i-1]+arr[i-2];
         }
         count=arr[i];
         printf("The Fibonacci number for %d is %d\n",m,count);
        // printf("The Fibonacci number for %d is %d\n",m,arr[i]);
    }
    return 0;
}
