#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main()
{
    long long int n,k,a,curr,sub;
    vector<long long int>vec;
    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    curr = 0;
    sub = 0;
    for(int i=0; i<k; i++)
    {


        if(i >=n)
        {
            cout << 0 << endl;
        }
        else
        {
            curr = vec[i] - sub;
            //sub += vec[i];
            if(curr != 0)
            {
                sub += curr;
            }
            if(curr <=0)
            {
                k++;
                continue;
            }
            cout << curr << endl;
        }
    }

    return 0;
}
