/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 19 / February / 2019
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main()
{
    long long int n,a,evSum,odSum,counter;
    vector<long long int> vec,even,odd;
    cin >> n;
    vec.push_back(0);
    for(int i=0; i<n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
    evSum = 0;
    odSum = 0;
    odd.push_back(0);
    even.push_back(0);
    for(int i=1; i<=n; i++)
    {
        if(i%2 == 0)
        {
            evSum += vec[i];
        }
        else
        {
            odSum += vec[i];
        }
        even.push_back(evSum);
        odd.push_back(odSum);
    }

    counter = 0;
    for(int i=1; i<=n; i++)
    {
        odSum = odd[i-1];
        evSum = even[i-1];

        evSum = evSum + (odd[odd.size()-1]-odd[i]);
        odSum = odSum + (even[even.size()-1]-even[i]);

        if(evSum == odSum)
        {
            counter++;
        }
    }
    cout << counter << endl;

    return 0;
}
