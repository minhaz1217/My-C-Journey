#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
   long long int n,m,exp,teams=0;
    cin >> n >>m;
    int big, small,temp;
    if(n>=m){
        big = n;
        small = m;
    }else{
        big = m;
        small = n;
    }
    if(small*2 <= big){
        teams = small;
    }else{
        teams = (big+ small )/3;
    }

    cout << teams << endl;


	return 0;
}
