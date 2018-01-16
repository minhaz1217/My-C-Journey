#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main()
{
    int tc,x,n,i,sum,beforeX, pnt,j,counter,tmp;
    cin >> tc;
    while(tc--)
    {
        cin >> x >> n;
        //cout << n << endl;
        sum = ((n*(n+1)) /2 )- x;
        if(sum %2 == 0 && n >= 3)
        {
            stack<int> st;
            tmp = sum/2;
            if(x == n){
                i = n-1;
            }else{
                i = n;
            }
           // cout << "HI ";
            //msg(i,tmp)
            while(tmp > i)
            {
                if(i==x){
                    i--;
                    continue;
                }
                if(tmp - i >= 0)
                {
                    tmp -= i;
                    //msg("PUSHED", i)
                    st.push(i);
                }
                i--;
            }
            if(tmp != x){
                st.push(tmp);
                for(i=1; i<=n; i++)
                {
                    if(i == x)
                    {
                        pnt = 2;
                    }
                    else if(i == st.top())
                    {
                        pnt = 1;
                        st.pop();
                    }
                    else
                    {
                        pnt = 0;
                    }
                    //check(st.size())
                    cout << pnt;
                }
                cout << endl;
            }else{
                cout << "impossible" << endl;
            }


        }
        else
        {
            cout << "impossible" << endl;
        }

    }

    return 0;
}
