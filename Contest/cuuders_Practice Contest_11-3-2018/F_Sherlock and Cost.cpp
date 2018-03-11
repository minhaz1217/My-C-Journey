#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 100005
int arr[MX];

int main(){
    int tc,n,minMax, maxMin,i,sum,sum1,MM=0,Mm=0,mM=0,mm=0, even, odd;

    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        //int arr[n+1];
        scanf("%d", &arr[1]);
        sum = 0;
        sum1 = 0;
        even = 0;
        odd = 0;
        odd+= arr[1];
        for(i=2;i<=n;i++){
            scanf("%d", &arr[i]);
            if(i%2==0){
                even += arr[i];
            }else{
                odd += arr[i];
            }
        }
        sum = 0;
        sum1 = 0;
        if(even >= odd){
            for(i=2;i<=n;i++){
                if(i%2 == 0){
                    sum += abs(arr[i] -1);
                }else{
                    sum += abs(1- arr[i-1]);
                }
            }
        }else{
            for(i=2;i<=n;i++){
                if(i%2 != 0){
                    sum1 += abs(arr[i] -1);
                }else{
                    sum1 += abs(1- arr[i-1]);
                }
            }
        }


        //msg(MM,Mm);
        //msg(mM,mm);
        printf("%d\n", max(sum1, sum));
    }

    return 0;
}
