#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){

    ios::sync_with_stdio(false);

    int tc,a,n,k,flag, j;

    cin >> tc;
    while(tc--){
        vector<int>vec,vec2;
        vec.push_back(0);
        vec2.push_back(0);
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a;
            vec.push_back(a);
        }
        for(int i=0;i<n;i++){
            cin >> a;
            vec2.push_back(a);
        }

        flag = 1;
        for(int i=1;i<=n-2 && flag;i++){
            a = vec2[i]-vec[i];
            //vec[i] = vec2[i];
            //msg(i,a)
            if(k>0)
            for(j=0;j<=2;j++){
                k = i+j;
                //msg2("K", i,k)
                if(k<=n){
                    vec2[k] -= (a*(j+1));
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(vec2[i] != vec[i]){
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            cout << "NIE" << endl;
        }else{
            cout << "TAK" << endl;
        }
    }
    return 0;
}
