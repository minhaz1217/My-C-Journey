#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long double kPrice,nMoney,wBananas,totalMoney;
    cin >> kPrice >> nMoney >> wBananas;
    totalMoney = wBananas/2 * (kPrice + kPrice*wBananas);
    if(nMoney >= totalMoney){
        cout << "0" << endl;
    }else{
        cout << (int)(totalMoney-nMoney) << endl;
    }

	return 0;
}
