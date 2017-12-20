#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

bool isLeapYear(int year)
{
if (year % 400 == 0) return true;
else if(year % 100 == 0) return false;
else if(year % 4 == 0) return true;
else return false;
}


int main(){
    int a,b,y1,y2,tc,ans = 0,i,caseCounter=1;
    cin >> tc;
    while(tc--){
        cin >> a >> b >> y1 >> y2;
        ans = 0;
        if(!(a == 29 && b== 2)){
                //c("H1")
            ans = y2 - y1;
        }else{
               // c("H2")
            for(i=y1+1;i<=y2;i++){
                if(isLeapYear(i)){
                    ans++;
                }
            }
        }
        cout << "Case " << caseCounter++ << ": " << ans << endl;
    }


    return 0;
}
