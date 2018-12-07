#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;



int main(){
    int a,i,sum,tc, j,mx,num,caseCounter =1;

    int prime[105];
    int arr[105];
    sum =1;
    mx = 105;
    for(i=0;i<=104;i++){
        prime[i] = 1;
    }
    for(i=2;i<=12;i++){
        if(prime[i] == 1){
            for(j=2;i*j<=105;j++){
                prime[i*j] = 0;
            }
        }
    }
    cin>> tc;
    while(tc--){
        cin >> a;
        for(i=2;i<=a;i++){
            arr[i] = 0;
        }


        for(i=2;i<=a;i++){
            num = i;
            for(j=2;j<=i;j++){
                if(prime[j]){
                    while(num%j == 0){
                        arr[j]++;
                        //cout << j << " " << num << endl;
                        num = num/j;
                    }
                }
            }
        }
        cout << "Case "<< caseCounter++ << ": " << a << " = 2 (" << arr[2] <<")";
        for(i=3;i<=a;i++){
            if(prime[i]){
                printf(" * %d (%d)", i, arr[i]);
            }
        }
        cout << endl;
    }



    return 0;
}
