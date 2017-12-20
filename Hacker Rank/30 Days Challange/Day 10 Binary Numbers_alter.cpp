#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long n,rem,big =0,counter = 0;
    cin >> n;
    while(n>0){
        rem = n%2;
        n=n/2;
        if(rem == 1){
            counter++;
            big = max(counter, big);
        }else{
            counter = 0;
        }
    }

    cout << big << endl;
	return 0;
}
