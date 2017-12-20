#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long n,arr[] = {4,7,44,47,74,77,444,447,474,477,744,747,774,777},flag =0,i;
    cin >> n;
    flag =0;
    for(i=0;i<12;i++){
        if(n%arr[i] == 0){
            flag = 1;
            break;
        }
    }
    if(flag ==1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
	return 0;
}
