#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define N 10000
#define alp 28
int tree[3*N][alp];
char arr[N];

void displayTree()
{
    int i,j,k,l;
    int starting=1;
    for(k=starting; k<alp; k++)
    {
        printf("%2d ", k);
    }
    cout << endl;
    for(l=starting; l<17; l++)
    {
        printf("%2d ", l);
        for(k = starting; k<alp; k++)
        {
            printf("%2d ", tree[l][k] );
            //cout << tree[8][k] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void build(int node,int l,int r)
{
    if(l==r)
    {
        for(int i = 1; i<alp; i++)
        {
            tree[node][i] = 0;
        }
        tree[node][arr[l]-'a'+1] = 1;

        //msg("NODE", node)
        //displayTree();
        return;

    }
    //msg(l,r)
    int right = (node * 2 ) + 1,
        left= node*2,
        mid=(l+r)/2;
    build(left,l,mid);
    build(right,mid+1,r);
    for(int i = 1; i<alp; i++)
    {
        tree[node][i] += tree[right][i]+tree[left][i];
    }
    //msg(node, l)
    //displayTree();
    return;
}
int sum;
void query(int node,int l,int r,int x,int y,char cc)
{
    if(r<x || y<l)
    {
        return;
    }
    if(x<=l && r<= y)
    {
        sum += tree[node][cc-'a'+1];
        return ;
    }
    int right =2*node+1,left= node*2,mid=(l+r)/2;
    query(left,l,mid,x,y,cc);
    query(right,mid+1,r,x,y,cc);

}

int main()
{
    sum =0;
    int t,n,x,y,q,k,i,j;
    long long r,l,prevSum;
    char cq;


    for(i=0;i<3*N;i++){
        for(j=0;j<alp;j++){
            tree[i][j] = 0;
        }
    }



    scanf("%d",&t);
    for(i = 1; i<=t; i++)
    {
        scanf("%d%d",&n,&q);
        for(j = 1; j<=n; j++)
        {
            cin >> arr[j];
            //scanf("%c", &arr[j]);
            //cout << arr[j] << endl;
        }
        //c("INputtaken")
        build(1,1,n);
        //c("BUILDED")
        //displayTree();
        while(q--)
        {
            scanf("%d %d %c",&l,&r,&cq);
            sum = 0;
            if(r> n){
                query(1,1,n,l,n,cq);
                l = n+1;
                query(1,1,n,1,r%n,cq);
                r = r - r%n;
                if(!(l>r)){
                    prevSum = sum;
                    query(1,1,n,1,n,cq);
                    prevSum = sum - prevSum;
                    sum = sum+ prevSum*(r - l+1) / n - prevSum;
                }
            }else if(l>n && r > n){
                query(1,1,n,l%n,n,cq);
                l = n+1;
                query(1,1,n,1,r%n,cq);
                r = r - r%n;
                if(!(l>r)){
                    prevSum = sum;
                    query(1,1,n,1,n,cq);
                    prevSum = sum - prevSum;
                    sum = sum+ prevSum*(r - l+1) / n - prevSum;
                }
            }else{
                query(1,1,n,l,r,cq);
            }
            cout<<sum<<endl;
        }
    }
}
