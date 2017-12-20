#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long myCounter, big,a,tc,prev;
    cin >> tc;
    cin >> prev;
    tc--;
    big = 1;
    myCounter = 1;
    while(tc--){
        cin >> a;
        if(a >= prev){
            myCounter++;
        }else{
            myCounter = 1;
        }
        if(myCounter > big){
            big = myCounter;
        }
        prev = a;
    }
    cout << big << endl;
	return 0;
}
