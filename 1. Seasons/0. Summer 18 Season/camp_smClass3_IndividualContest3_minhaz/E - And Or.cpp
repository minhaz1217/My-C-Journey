#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 104
bool ison(long long int a, int pos){
    return ( (a&(1<<pos)) );
}


int main(){

    long long int tc, a,b,mOr, mAnd ,temp, counter,myMax, currOr, currAnd,i,caseCounter=1,counter2;

    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld %lld", &a , &b);
        temp = b;
        counter = 0;
        while(temp != 0){
            temp = (temp >> 1);
            counter++;
        }
        temp =a;
        counter2= 0;
        while(temp != 0){
            temp = (temp >> 1);
            counter2++;
        }
        //msg2("Counter", counter, counter2)
        myMax = (1<<counter)-1;
        mOr = b;
        mAnd = a;
        if(b == a){
            mOr = b|b;
            mAnd = b&b;
        }else{
            mOr = (b|a)|(b-1);
            mAnd = (b&a)&(b-1);
           // bitset<6>bb(b);
            //msg("C", bb.count())
            //msg(counter, "CC")
            mOr = b;
            for(i=0;i<counter;i++){
                if( !ison(b,i) ){
                    if(b-(i) >= a ){
                        mOr = mOr^(1<<i);
                        //msg("HI", i)
                    }
                }
            }
            mAnd = a;
            for(i=0;i<counter2;i++){
                if( ison(a,i) ){
                    if(b-a >= (2<<i)){
                        mAnd = mAnd^(1<<i);
                        //msg("HI", i)
                    }
                }
            }
        }
        mAnd &= a;
        mAnd &= b;
        mOr |= a;
        mOr |= b;
        //cc(bitset<8>(b))
        printf("Case %lld: %lld %lld\n", caseCounter++, mOr, mAnd);
        //msg(currOr, currAnd);

    }

    return 0;
}
