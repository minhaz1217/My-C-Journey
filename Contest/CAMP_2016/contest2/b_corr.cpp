#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int tc,n,caseCounter = 1,test,p,i = 0,counter = 1;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        i = 0;
        counter = 1;
        if(n%2 == 0 && n>0){
            while(n%2 == 0)
            {
                i++;
                counter *= 4;
                n = n/2;
            }
            cout << "Case " << caseCounter++ << ": " << counter << " " << n  << endl;
        }else if(n%2 != 0){
            cout << "Case " << caseCounter++ << ": " << 1 << " " << n  << endl;

        }else if(n == 0){
            cout << "Case " << caseCounter++ << ": " << 0 << " " << 0  << endl;
        }
        /*
        if(n == 0){
            counter = 0;
        }else if(n%2 != 0 ){}
        */

    }
    return 0;
}
