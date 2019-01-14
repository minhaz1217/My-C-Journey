#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define MX 104
int main(){
    int n,k,a,myMax,c,edu,soc;
    vector<int>vec;
    cin >> n >> k;
    int arr[MX];
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    myMax = INT_MIN;
    for(int b=1;b<=n;b++){

        for(int i=0;i<MX;i++){
            arr[i] = 1;
        }
        for(int i=-1000;i<=1000;i++){
            c = b+ (i*k);
            if(c>=1 && c <=n){
                arr[c-1] = 0;
            }
        }
        edu=0;
        soc = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == 1){
                if(vec[i] == 1){
                    edu++;
                }else{
                    soc++;
                }
            }
        }
        myMax = max(myMax, abs(edu-soc));

    }
    cout << myMax << endl;

    return 0;
}
