#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main()
{
    long long a,b,flag,c,d,e,f,tc,n,x1,x2,y1,y2,z1,z2, res,caseCounter = 1;
    cin >>tc;
    while(tc--)
    {
        /*
        x2 = 1001;
        y2 = 1001;
        z2 = 1001;
        x1 = 0;
        y1 = 0;
        z1 = 0;
        */
        flag = 0;
        cin >> n;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        if(n==1){
            res = abs(x1-x2) * abs(y1-y2) * abs(z1-z2);
            cout << "Case "<< caseCounter++ << ": " << res << endl;
            continue;
        }
        n--;
        while(n--)
        {
            cin >> a >> b >> c >> d >> e >> f;
            if(a>=x1 && a<=x2){
                x1 = max(a,x1);
                flag =1;
                //check(1)
            }
            if(b>=y1 && a<=y2){
                y1 = max(b,y1);
                flag =1;
                //check(1)
            }
            if(c>=z1 && c<=z2){
                z1 = max(c, z1);
                flag =1;
                //check(1)
            }
            if(d>=x1 && d<=x2){
                x2 = min(d, x2);
                flag =1;
                //check(1)
            }
            if(e>=y1 && e<=y2){
                y2 = min(e, y2);
                flag =1;
                //check(1)
            }
            if(f>=z1 && f<=z2){
                z2 = min(f, z2);
                flag =1;
                //check(1)
            }
        }
        if(flag == 1){
            res = abs(x1-x2) * abs(y1-y2) * abs(z1-z2);
        }else{
            res = 0;
        }
        cout << "Case "<< caseCounter++ << ": " << res << endl;


    }
    return 0;
}
