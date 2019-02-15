#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int> z_algo(string s)
{
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++)
    {
        z[i] = max(0,min(z[i-x],y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
        {
            x = i;
            y = i+z[i];
            z[i]++;
        }
    }
    return z;
}

vector<int>zz;

int main()
{
    _INIT;
    int tc, finalMx,sstart,send,mx1,mx2, caseCounter = 1;
    string str1, str2, str3, smallStr, midStr, largeStr;

    cin >> tc;
    while(tc--)
    {
        finalMx = 0;
        cin >> str1 >> str2 >> str3;
        if(str1.size() <= str2.size() && str1.size() <= str3.size())
        {
            smallStr = str1;
            if(str2.size()<= str3.size())
            {
                midStr = str2;
                largeStr = str3;
            }
            else
            {
                midStr = str3;
                largeStr = str2;
            }
        }
        else if(str2.size() <= str1.size() && str2.size() <= str3.size())
        {
            smallStr = str2;
            if(str1.size()<= str3.size())
            {
                midStr = str1;
                largeStr = str3;
            }
            else
            {
                midStr = str3;
                largeStr = str1;
            }
        }
        else
        {
            smallStr = str3;
            if(str1.size()<= str2.size())
            {
                midStr = str1;
                largeStr = str2;
            }
            else
            {
                midStr = str2;
                largeStr = str1;
            }
        }

        str1 = "";
        for(int i=0; smallStr[i]; i++)
        {
            str1 = smallStr.substr(i,smallStr.size()-i);
            string myTemp = str1 + "$";
            sstart = myTemp.size();
            myTemp = myTemp + midStr;
            send = myTemp.size();
            myTemp = myTemp + "#" + largeStr;
            zz = z_algo(myTemp);
            mx1 = mx2 = 0;
            for(int j=sstart; j<send; j++)
            {
                mx1 = max(mx1, zz[j]);
            }
            sstart = send;
            for(int j=sstart; j<zz.size(); j++)
            {
                mx2 = max(mx2, zz[j]);
            }
            //mx(mx1,mx2)
            finalMx = max(finalMx, min(mx1, mx2));
            if(finalMx >= str1.size())
            {
                break;
            }

        }
        cout << "Case " << caseCounter++ << ": " << finalMx << endl;
    }

    return 0;
}
