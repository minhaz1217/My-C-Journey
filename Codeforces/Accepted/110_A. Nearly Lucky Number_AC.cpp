#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long int tc,counter = 0;
    cin >> tc;
    while(tc!=0){
        if(tc%10 == 4 || tc%10 == 7){
            counter++;
        }
        tc = tc/10;
    }
    if(counter == 4 || counter == 7 || counter == 44 || counter ==47 || counter == 74 || counter == 77){
        cout << "YES" << endl;
    }else{
        cout << "NO"<< endl;
    }
	return 0;
}
