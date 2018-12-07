#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 104

int main(){

    long long int tc, a,b, temp, counter,myMax, currOr, currAnd,i,caseCounter=1;

    scanf("%lld", &tc);
    while(tc--){
        //scanf("%lld %lld", &a , &b);
        temp = rand()%100;
        //srand(temp);
        counter = rand()%100;
        a = min(temp, counter);
        b = max(temp, counter);
        msg(a,b)
        temp = b;
        counter = 0;
        while(temp != 0){
            temp = (temp >> 1);
            counter++;
        }
        myMax = (1<<counter)-1;
        currOr = b;
        currAnd = b;
        for(i=b;i>=a;i--){
            currOr = (currOr | i);
            currAnd = (currAnd & i);
            if(currOr == myMax && currAnd == 0){
                // break;
            }
        }
        printf("Case %lld: %lld %lld\n", caseCounter++, currOr, currAnd);
        //msg(currOr, currAnd);

    }

    return 0;
}
