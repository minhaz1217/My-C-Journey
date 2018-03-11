#include<bits/stdc++.h>
using namespace std;
long int myPow(long int a, long int b){

    if(b == 1){
        return a;
    }else if(b == 0){
        return 1;
    }

    if(b%2 == 0){
        return myPow(a, b/2) * myPow(a, b/2);
    }else{
        return myPow(a, b/2) * myPow(a, (b)/2 + 1);
    }
}
int main(){
    //cout << myPow(2,3);

    long int tc,num1,num2,c;
    cin >> tc;
    while(tc--){
        cin >> num1 >> num2;
        cout << myPow(num1,num2) %10 << endl;
    }
  return 0;
}
