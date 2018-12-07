#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    int tc,n,sum=0,big = 0,i;
    while(1){
        sum =0;
        big = 0;
        cin >> tc;
        if(tc == 0){
            break;
        }
        while(tc--){
            cin >> n;
            sum += n;
            big = big > n? big : n;
        }
        //msg("SUM", sum)
        // either i = big or i= big+1
        for(i=big;i<sum;i++){
            if(sum % i ==0){
                if(i==big){
                    continue;
                }
                break;
            }
        }
        cout << i << endl;
    }
    return 0;
}
