#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;


int main(){
    long long int n,i,last, sum, left, right,sz;

    long long int l = 343, aa = 4;
    //cc(fillLeft(l,aa))
    //cc(fillRight(l,aa))
    vector<string>vec[10];
    vec[2].push_back("00");
    vec[2].push_back("01");
    vec[2].push_back("81");
    vec[4].push_back("0000");
    vec[4].push_back("0001");
    vec[4].push_back("2025");
    vec[4].push_back("3025");
    vec[4].push_back("9801");
    vec[6].push_back("000000");
    vec[6].push_back("000001");
    vec[6].push_back("088209");
    vec[6].push_back("494209");
    vec[6].push_back("998001");
    vec[8].push_back("00000000");
    vec[8].push_back("00000001");
    vec[8].push_back("04941729");
    vec[8].push_back("07441984");
    vec[8].push_back("24502500");
    vec[8].push_back("25502500");
    vec[8].push_back("52881984");
    vec[8].push_back("60481729");
    vec[8].push_back("99980001");

    while(scanf("%lld", &n)){

        for(i=0;i<vec[n].size();i++){
            cout << vec[n][i]<< endl;
            //printf("%s\n", vec[n][i]);
        }

        /*
        if(n == 1){
            last = 9;
        }else if(n== 2){
            last = 99;
        }else if(n== 4){
            last = 9999;
        }else if(n== 6){
            last = 999999;
        }else if(n== 8){
            last = 99999999;
        }
        sum = 1;
        for(i=1;i<=n/2;i++){
            sum = sum * 10;
        }
        for(i=0;i<=last;i++){
            sz = log10(i);
            if(sz <= n/2){
                left = 0;
                right = i;
            }else{
                left = i/sum;
                right = i % sum;
            }

            //msg2(i,left, right)
            if( (left+right)*(left+right) == i){
                //cout << i << endl;
                if(n== 2){
                    printf("%02lld\n",i);
                }else if(n== 4){
                    printf("%04lld\n",i);
                }else if(n== 6){
                    printf("%06lld\n",i);
                }else if(n== 8){
                    printf("%08lld\n",i);
                }
            }
        }
        */

    }
    return 0;
}
