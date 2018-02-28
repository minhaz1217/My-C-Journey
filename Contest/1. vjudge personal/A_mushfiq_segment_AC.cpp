#include <stdio.h>
#include <math.h>
#define N 1000004
#define inf -1
long long arr[N+10],tree[4*N+4];
void build(long long node,long long l,long long r)
{
    if(l==r)
    {
        tree[node] = arr[l];
        return ;
    }
    long long  left = node*2,right = node*2+1,mid = (l+r)/2;
    build(left,l,mid);
    build(right,mid+1,r);
    //tree[node] = max(tree[left],tree[right]);
    if(tree[left]>= tree[right])
    {
        tree[node] = tree[left];
    }
    else
    {
        tree[node]= tree[right];
    }

}
long long  q1,q2,ans;
long long query(long long node,long long l,long long r,long long q1,long long q2)
{
  //  printf("Point 1\n");
    if(r<q1 || q2<l)
    {
        return -1;
    }
    if(q1<=l && r<=q2)
    {
        //printf("%lld ",tree[node]);
        return tree[node];
    }
    long long mid = (l + r)/2,left=node*2,right = node*2 +1;
    long long ans1 = query(left,l,mid,q1,q2);
    long long ans2 = query(right,mid+1,r,q1,q2);

    if(ans1 == -1){
        ans = ans2;
    }
    if(ans2 == -1){
        ans = ans1;
    }

    if(ans1 > ans2)
    {
        ans = ans1;
    }
    else
    {
        ans = ans2;
    }
    return ans;
}
int main()
{
    long long n,k,i,j;
    scanf("%lld",&n);
    for(i = 1; i<=n; i++)
    {
        scanf("%lld",&arr[i]);
    }
    scanf("%lld",&k);
    build(1,1,n);
    for(j = 1; j+k-1<=n; j++)
    {
        q1 = j;
        q2 = j+k-1;
        //printf("%lld %lld\n",q1,q2);

        //printf("%lld\n",q2) ;// j hocche n bar bar change hoche ar K kore sub array ke niccche
        printf("%lld ",query(1,1,n,q1,q2));
    }
    printf("\n");
    return 0;
}
