#include<bits/stdc++.h>
//#include<iostream>
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a, b) cout <<  a << " : " << b << endl;
#define msg2(a, b, c) cout <<  a << " : " << b << " : " << c << endl;
using namespace std;

#define MX 100000000
bool prime[MX];
vector<long long int>  vec;
void sieve(){
    int i,j, root;
    root = sqrt(MX )+1;
    for(i=0;i<MX;i++) prime[i] = 1;
    for(i=2;i<=root;i++){
        if(prime[i]){
            for(j=i;j*i<=MX;j++){
                prime[i*j] = 0;
            }
        }
    }

    vec.push_back(0);
    vec.push_back(2);
    int last = 1;
    for(i=3;i<MX;i++){
        if(prime[i]){
            vec.push_back(vec[last] + i);
            last++;
        }
    }

}


int main(){
    long long int tc,x,y;
    sieve();
    scanf("%lld", &tc);
    //cc(vec.size())
    /*
    for(int i=1;i<=5;i++){
        cc(vec[i])
    }
    */
    while(tc--){
        scanf("%lld %lld", &x, &y);
        //msg(vec[x], vec[y])
        printf("%lld\n", (vec[y] - vec[x-1]));
    }

    return 0;
}
