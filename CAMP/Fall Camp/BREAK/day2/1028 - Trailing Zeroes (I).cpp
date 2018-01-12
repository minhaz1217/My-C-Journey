#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main()
{
    long long  tc,i,big,root,j,temp,a=1,div=1,caseCounter =1,num;

    bool prime[1000400];
    for(i=0; i<=1000400; i++)
    {
        prime[i] = 1;
    }
    root = sqrt(1000400)+1;
    for(i=2; i<= root; i++)
    {
        //c("HI")
        if(prime[i])
        {
            for(j=2; i*j <= 1000400; j++)
            {
                prime[i*j] = 0;
            }
        }
    }

    cin >> tc;
    //int arr[tc+1];
    for(i=0; i<tc; i++)
    {
        cin >> num;
        temp = num;
        j = 0;
        a = 1;
        div = 1;
        //cout << temp << endl;
        root = sqrt(num)+1;
        for(j=2; j<=root; j++)
        {
            if(prime[j] == 1)
            {
                a = 1;
                //msg("I", j)
                //cout << "HI" << endl;
                while(temp%j == 0 && temp > 1)
                {
                    //msg(temp,j)
                    a++;
                    temp = temp / j;
                }
                div = div*a;
            }
        }
        if(temp > 1)
        {
            div = div * 2;
        }
        /*
        if(div - 1 == 0){
            div = 1;
        }else{
            div = div -1;
        }
        */
        //msg(arr[i] , prime[arr[i]])

        cout << "Case " << caseCounter++ << ": " << div-1 << endl;
    }
    return 0;
}
