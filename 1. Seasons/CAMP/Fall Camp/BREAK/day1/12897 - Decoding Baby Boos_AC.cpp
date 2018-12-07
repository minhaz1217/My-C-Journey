#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main()
{
    int i,q,tc;
    char a,b;
    char c[27];
    string str;
    cin >> tc;
    while(tc--)
    {
        a = 65;
        for(i=0; i<27; i++)
        {
            c[i] = a;
            a++;
            //cout << c[i] << endl;
        }
        cin >> str;
        cin >> q;
        while(q--)
        {
            cin >> a >> b;
            for(i=0; i<26; i++)
            {
                if(c[i] == b)
                {
                    c[i] = a;
                    //cout << c[i] << endl;
                }
            }
        }
        /*
        for(i=0;i<27;i++){;
        cout << c[i] << endl;
        }
*/

        char temp;
        for(i=0; str[i]; i++)
        {
            temp = str[i];
            if(temp >= 65 && temp <= 90 )
            {
                cout << c[temp-65];
            }
            else
            {
                cout << temp;
            }
        }
        cout << endl;
    }




    return 0;
}
