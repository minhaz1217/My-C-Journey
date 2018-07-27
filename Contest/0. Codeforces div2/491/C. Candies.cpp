#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int i,n,temp,l,counter,steps;
    cin >> n;
    /*
    for(l=1;l<1000;l++){
        n = l;
        */
    for(i=1;i<n;i++){
        temp = n;
        counter = 0;
        steps = 0;
        while(temp > 0){
            //msg(i,temp)
            temp = temp-i;
            counter += i;

            if(temp >10){
                temp = temp -temp *.1;
            }
            steps++;
        }
        //msg(i,steps)
        if(counter >= n/2){
            break;
        }
    }
    /*
    msg(l,i)
    }
    */
    cout << i << endl;

    return 0;
}
