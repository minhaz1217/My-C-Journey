#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
int main()
{
    int a,b,c,i,j,n,k,flag=0;
    char x[40][40],y[40],z;
    scanf("%d",&n);
    char ccc;

    /*
            getchar();
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            scanf("%c",&x[i][j]);
             //cc(x[i][j])
        }
       for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout  << x[i][j] << " ";
        }
        cout << endl;
       }
       */

    for(i=0; i<n; i++)
    {
        scanf("%s", &x[i]);
    }
//    for(i=0; i<n; i++)
//    {
//        for(j=0; j<n; j++)
//        {
//            cout  << x[i][j] << " ";
//        }
//        cout << endl;
//    }
    for(i=0; i<n; i++)
        for(j=0; j<n-1; j++)
        {
            k=j+1;
            while(k!=n)
            {
                if(x[i][j] == x[i][k])
                {
                    printf("No\n");
                    return 0;
                }
                k++;
            }
        }

        for(i=0; i<n; i++)
        for(j=0; j<n-1; j++)
        {
            k=j+1;
            while(k!=n)
            {
                if(x[j][i] == x[k][i])
                {
                    printf("No\n");
                    return 0;
                }
                k++;
            }
        }
        for(i=0;i<n-1;i++)
        {
            if(x[0][i]>x[0][i+1] || x[i][0] > x[i+1][0])
            {
                printf("Not Reduced\n");
                return 0;
            }
        }
        printf("Reduced\n");

    return 0;
}
