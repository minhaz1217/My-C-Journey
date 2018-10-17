#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define sf scanf
#define pf printf
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) ((a*b)/ GCD(a,b))


#define MOD 1000000007
#define M 320
#define MM 100010


template<class T>
inline bool fs(T &x){
    int c = getchar();
    int sgn = 1;
    while(~c && c< '0' || c>'9' ){
        if(c =='-') sgn= 1;
        c = getchar();
    }
    for(x = 0; ~c && '0' <=c && c<= '9' ; c = getchar()){
        x = x*10 + c - '0';
    }
    x *= sgn;
    return ~c;
}

int main(){
    int test,n,a;

    fs(test);
    cout << test << endl;
    while(test--){
        fs(n);
        cout << n << endl;
        for(int i=0;i<n;i++){
            fs(a);
            cout << "HI" << a << endl;
        }
    }


    return 1;
}
