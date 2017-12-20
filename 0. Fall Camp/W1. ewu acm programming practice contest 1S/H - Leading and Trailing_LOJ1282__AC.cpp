#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
long long fast_pow(long long base,long long power, int mod)
{
    long long result = 1;
    long long value = base;
    while(power>0)
    {
        if(power&1){
            result = result*value;
            if(mod!=-1) result = result%mod;
        }
        value = value*value;
        if(mod!=-1)value = value%mod;
        power /= 2;
        //power >>= 1;
    }
    return result;
}

int main(){

    long long n,k,i,sum,tc,caseCounter = 1;
    double sum2,l;
    cin >> tc;
    while(tc--){
        cin >> n >> k;
        sum =1;
        sum = fast_pow(n,k,1000);
        l = k*log10(n);
        l = l-(int)(l);
        sum2 = (double)pow(10.00,(double)l);
        sum2 = (sum2*100.00);
        //check(sum2)

        cout << "Case "<< caseCounter++ << ": ";
        if(sum2 == floor(sum2)){
            cout << sum2 << " ";
        }else{
            cout << (int)sum2 << " ";
        }


        if(sum==0){
            cout << "000" << endl;
        }else if(sum < 10){
            cout << "00" << sum << endl;
        }else if(sum<100){
            cout << "0" << sum << endl;
        }else{
            cout << sum << endl;
        }


    }

    return 0;
}
