#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main()
{
    int i, tc,counter = 0;
    double sum,avg;
    while(1)
    {

        cin >> tc;
        int arr[tc];
        if(tc==-1)
        {
            break;
        }
        sum = 0;
        for(i=0; i<tc; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        sort(arr, arr+tc);
        avg = sum/tc;
        if(avg - (int)avg != 0)
        {
            //msg(avg, avg- (int)avg)
            cout << -1 << endl;
        }
        else
        {
            counter = 0;
            for(i=0; i<tc; i++)
            {
                if(arr[i] < avg)
                {
                    counter += avg - arr[i];
                }
                else
                {
                    break;
                }
            }
            //msg("H" ,counter)
            cout << counter << endl;
        }
    }

    return 0;
}
