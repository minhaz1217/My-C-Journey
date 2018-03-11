#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define SV 100004
int prime[SV];
vector<int>primes;
int number[SV];
void sieve(){
    int root,counter,i,j;
    root = sqrt(SV) + 1;
    for(i=0;i<SV;i++){
        prime[i] = 1;
    }
    for(i=2;i<=root;i++){
        if(prime[i]){
            for(j=i;j*i <= SV;j++){
                prime[i*j] = 0;
            }
        }
    }
    counter = 0;
    for(i=1;i<SV;i++){
        if(prime[i]){
            counter++;
        }
        number[i] = counter;
    }
}


int main(){
    sieve();
    int tc,n,ans,i;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        ans = number[n];
        if(ans%2 == 0){
            printf("Alice\n");
        }else{
            printf("Bob\n");
        }
        //printf("%d")
    }
    return 0;
}
