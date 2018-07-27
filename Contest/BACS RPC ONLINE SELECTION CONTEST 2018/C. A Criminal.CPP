#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

long long int findLucky(long long int i){
    long long int lucky,man;
    if(i==1)return 1;
    if( (2<<(int)log2(i)-1) == i){
        lucky = 0;
        //msg("HI", lucky)
    }else{
        man = (2<<(int)ceil(log2(i)-1));
        lucky = man - 2*(man - i);
    }
    return lucky+1;

}

int main(){
    int i,tc,x,l,n,caseCounter =1;

    cin >> tc;
    while(tc--){
        long long int counter, mCounter,lucky;
            counter = 0;
        mCounter= 0;
        cin >> x >> l >> n;
        for(i=l;i<=n;i++){
            lucky = findLucky(i);
            if(lucky == x){
                counter++;
            }
            if( !(i< x)){
                mCounter++;
            }
        }
        if(counter == 0){
            if(l>=x){
                mCounter = 1;
            }else{
                mCounter = n;
                counter = n-x;
            }
        }
        cout <<"Case "<< caseCounter++<<": "<< counter << "/" << mCounter << endl;



    }


    return 0;
}
