#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 1000
int par[MX];
int findSet(int x)
{
    if(par[x] == x)
    {
        return x;
    }
    par[x] = findSet(par[x]);
    //par[x] = findSet(par[x]);
    //return par[x];
    return par[x];
}
int combineSet(int x, int y)
{
    par[findSet(x)] = findSet(y);
}


int main()
{
    int tc,counter,n,i,chCounter = 0,x,y,ta=1;
    char a,b,c;
    string str;

    cin >> tc;
    while(tc--)
    {
        cin >> c;
        counter = 0;
        n = c - 'A'+1;

        for(i=1; i<=n; i++)
        {
            par[i] = i;
        }
        cin.ignore();
        while(1)
        {
            getline(cin,str);
            //msg("HI", str.size())
            if(str.length() <2)
            {
                break;
            }
            x = str[0] - 'A' +1;
            y = str[1] - 'A' +1;
            //msg(x,y)
            if(x>y)
            {
                swap(x,y);
            }
            if(findSet(x) != findSet(y))
            {
                //msg2("Making set", findSet(x),findSet(y))
                combineSet(x,y);
            }

            //cout << counter << endl;
        }

        counter = 0;
        for(i=1; i<=n; i++)
        {
            if(par[i] == i)
            {
                counter++;
            }
            //msg(i,par[i])
        }
        if(ta>1){
            cout << endl;
        }
        ta++;
        cout << counter << endl;
        //msg("ANS", counter)
    }

    return 0;
}
