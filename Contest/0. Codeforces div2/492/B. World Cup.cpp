#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int n,a,i,firstMin, secondMin,mm,myAns,start,counter=0;
    cin >> n;
    pair<long long int, long long int> pp[n];
    myAns = 0;
    for(i=0;i<n;i++){
        cin >> a;
        pp[i].first = a;
        pp[i].second = i;
        mm = min(mm, pp[i].first);
        if(pp[i].first < i+1 && !myAns){
            myAns = i+1;
        }
    }
    //cc(myAns)
    if(myAns == 0){

        for(i=0;i<n;i++){
            pp[i].first -= mm;
            if(pp[i].first == 0){
                start = pp[i].second;
            }
        }
        i = mm%n;
        //msg("I", i)
        //cc(i)
        while(1){
            //msg(i, pp[i].first)
            if(pp[i].first - counter <= 0){
                myAns = pp[i].second+1;
                break;
            }else{
                pp[i].first -= counter;
                counter++;
            }
            i++;
            i = i%n;
        }
    }
    cout << myAns << endl;
    //cc(myAns);

    return 0;
}
