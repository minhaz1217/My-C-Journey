#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a, b) cout << a << " : " << b << endl;
#define msg2(a, b, c ) cout << a << " : " << b << " : " << c << endl;
#define MX 1000004
bool prime[MX+4];
int val[MX+4];
void sieve(){
    int arrSize, root, i,j, t,counter,sum;
    arrSize = MX;
    root = sqrt(MX) +1;
    for(i=0;i<arrSize;i++){
        prime[i] = 1;
    }
    prime[0] = 0;
    for(i=2;i<=root;i++){
        if(prime[i]){
            for(j=i;j*i<=arrSize;j++){
                prime[i*j] = 0;
            }
        }
    }
    counter = 0;
    prime[1] = 0;
    for(i=1;i<MX;i++){
        if(prime[i]){
            t = i;
            sum = 0;
            while(t!= 0){
                sum += t%10;
                t = t/10;
            }
            if(prime[sum]){
                counter++;
            }
        }
        val[i] = counter;
    }
}

int main(){
    val[0] = 0;
    sieve();

    int counter = 0;
    for(int i=0;i<=100;i++){
        //msg(i, val[i])
    }

    int n,a,b, mx,mn;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &a, &b);
        mx = b;
        mn = a;

        mx = a>=b? a : b ;
        mn = a<=b? a : b ;
        a = mn;
        b = mx;
        printf("%d\n", (val[b] - val[a-1]));
        //printf("%d\n", (val[b] - val[a-1]));
    }
    return 0;
}
