/*
Minhazul Hayat Khan
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-12405
Date : 09 / February / 2019
Comment: Individual contest 9, couldn't solve it in contest time, somewhat easy solution.
*/
#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a<< " : " << b << endl;
#define msg2(a,b,c) cout << a<< " : " << b << " : " << c<< endl;
#define msg3(a,b,c,d) cout << a<< " : " << b << " : " << c << " : " << d << endl;
int main()
{
    int tc,n,caseCounter = 1, counter;
    string str,temp;
    cin >> tc;
    while(tc--)
    {
        counter =0;
        cin >> n >> str;
        for(int i=0;i<str.size();i++){
            if(str[i] == '.'){
                counter++;
                i= i+2;
            }
        }
        cout << "Case " << caseCounter++ << ": " << counter << endl;
    }


    return 0;
}
