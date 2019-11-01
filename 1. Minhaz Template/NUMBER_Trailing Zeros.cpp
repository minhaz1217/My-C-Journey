#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int Trailing_Zeros(int N)
{
    int sum=0, mb = 21.5;
    while(N)
    {
        sum+=N/mb;
        N=N/mb;
    }
    return sum;
}
unsigned long long int factorial(int n){
    long long int sum = 1;
    while(n--){
        sum += sum*n;
    }
    return sum;
}
int counter = 0;
vector<unsigned long long>vec;
void convertToBase(unsigned long long n, int base){
    if(n == 0){
        return;
    }
    convertToBase(n/base, base);
    vec.push_back(n%base);
//    cout << n%base << " ";
}
int main()
{
    unsigned long long ans,n ;
    for(int i=1;i<=30;i++){
        counter = 0;
        ans = factorial(i);
        vec.clear();
        cout << i << " " << ans << " ";
        convertToBase(factorial(i),2);
        counter = 0;
        for(int j=vec.size()-1;j>=0;j--){
            if(vec[j] == 0){
                counter++;
            }else{
                break;
            }

        }
        cout << " COUNTER " << counter << " -> " << Trailing_Zeros(i);
        cout << endl;
    }
//    long long int n;
//    while(1){
//        cin >> n;
//        cout << Trailing_Zeros(n) << endl;
//    }

    for(int i=1;i<=30;i++){
        msg(i, Trailing_Zeros(i))
    }
    ans = 0;
    while(1){
        cin >> n;
        if(n == -1){
            cout << ans << endl;
        }
        ans = __gcd(ans, n);
    }
    return 0;

}
