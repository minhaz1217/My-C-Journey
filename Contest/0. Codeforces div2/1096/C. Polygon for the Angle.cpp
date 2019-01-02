#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int angle, corner, div,tc,ang,ans=0;

    cin >> tc;
    while(tc--){
        cin >> ang;
        //cc(ang)
        ans = 0;
        for(int i=3;i<=180;i++){
            angle = (i-2)*180;
            corner = angle / i;
            if(corner *i!= angle){
                continue;
            }
            div = corner / (i-2);
            if(div * (i-2) != corner){
                continue;
            }
            //msg3(i,angle, corner, div)
            if(ang % div == 0 && div*(i-2)>=ang ){
                ans = i;
                //msg2(angle, corner, div)
                break;
            }
            //msg(i,angle)
        }
        if(ans == 0){
            cout << "-1" << endl;
        }else{
            cout << ans << endl;
        }
    }

    return 0;
}
