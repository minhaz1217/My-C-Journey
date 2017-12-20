#include<iostream>
#include<math.h>
using namespace std;
#define check(a) cout<<a<< endl;
int convertDecimalToBinary(int num){
    int i,bin=0,remain=0;
    for(i=0;pow(2,i) <= num;i++){}
    bin = bin*10 + 1;
    remain = num - pow(2,i-1);
    for(i=i-2;i>=0;i--){
        if(pow(2,i) > remain){
            bin = bin*10;
        }else{
            bin = bin*10 + 1;
            remain -= pow(2,i);
        }
    }
    return bin;
}
int main(){

    int num = 21,i,bin=0,remain=0;
    for(i=0;pow(2,i) <= num;i++){}

    bin = bin*10 + 1;
    remain = num - pow(2,i-1);
    for(i=i-2;i>=0;i--){
        if(pow(2,i) > remain){
            bin = bin*10;
        }else{
            bin = bin*10 + 1;
            remain -= pow(2,i);
        }
    }
    cout << bin << endl;
    int a =7;
    int n = pow(2, a);
    for(int i =1;i<n;i++){
            cout << i << ": ";
        cout << convertDecimalToBinary(i) << endl;
    }
    //cout << convertDecimalToBinary(15) << endl;
	return 0;
}
