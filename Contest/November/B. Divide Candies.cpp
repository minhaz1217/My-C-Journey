#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int n,m,counter1= 0, counter2= 0;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if( (i*i + j*j) % m== 0){
                if(i!=j){
                    counter1++;
                }else{
                    counter2++;
                }
            }
        }
    }
    msg(counter1,counter2)
    msg("ANS", counter1*2 + counter2)

    return 0;
}
