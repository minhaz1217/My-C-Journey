#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long num,div;
    cin >> num;
    if(num%2 == 0){
        div = num / 2;
        cout << div << endl;
        while(div--){
            cout << "2 ";
        }
        cout << endl;
    }else{
        div = num /2;
        cout << div << endl;
        div--;

        while(div--){
            cout << "2 ";
        }
        cout << "3 "<< endl;
    }
	return 0;
}
