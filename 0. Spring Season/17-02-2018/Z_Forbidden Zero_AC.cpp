#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,a[]= {-1,-1,-1,-1,-1,-1,-1,-1};
    int b,m,n,t,i=0,temp;
    cin >> x ;
    x++;
    while(1)
    {
        temp = x;
        i=0;
        while(temp!=0)
        {
            a[i] = temp%10;
            temp = temp/10;
            i++;
        }
        if( (a[0] != 0 && a[1] != 0 && a[2]!= 0 && a[3]!= 0 && a[4] != 0 && a[5]!=0 && a[6] !=0 ))
        {
            cout << x << endl;
            return 0;
        }
        else x++;
    }
    return 0;
}
