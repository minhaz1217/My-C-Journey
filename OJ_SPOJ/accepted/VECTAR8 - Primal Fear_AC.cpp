//https://www.spoj.com/problems/VECTAR8/
#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a<< " : " << b << endl;
#define msg2(a,b,c) cout << a<< " : " << b << " : " << c<< endl;
#define msg3(a,b,c,d) cout << a<< " : " << b << " : " << c << " : " << d << endl;
#define MX 1000400
bool mark[MX];
int mark2[MX];
void sieve(){
    int root = sqrt(MX)+1;
    for(int i=0;i<MX;i++){
        mark[i] = 1;
    }
    for(int i=2;i<=root;i++){
        if(mark[i]){
            for(int j=i;j*i<=MX;j++){
                mark[i*j] = 0;
            }
        }
    }
    mark[1] = 0;
}
bool hasZero(long long int n){
    while(n!=0){
        if(n%10 == 0){
            return 1;
        }
        n = n/10;
    }
    return 0;
}
void dfs(long long int n){
    long long int temp = n%10,a,flag = 1;
    //msg("REC", n)
     a= 1;
    while(temp != n){
        a = a*10;
        temp = n%a;
        if(mark[temp] == 0){
            flag = 0;
            break;
        }
    }
    if(flag == 0){
        mark2[n] = 0;
    }else{
        mark2[n] = 1;
    }
}
int main(){
    int tc,n,counter,caseCounter =1,currMin,cnt,flag,sum;
    string str, temp;
    sieve();
    for(int i=MX-1;i>=1;i--){
        if(!hasZero(i)){
            if(mark[i] == 1){
                dfs(i);
            }else{
                mark2[i] = 0;
            }
        }else{
            mark2[i] = 0;
        }
    }
    sum = 0;
    for(int i=0;i<MX;i++){
        sum += mark2[i];
        mark2[i] = sum;
    }

    cin >> tc;
    while(tc--){
        cin >> n;
        cout << mark2[n] << endl;
    }
    return 0;
}
