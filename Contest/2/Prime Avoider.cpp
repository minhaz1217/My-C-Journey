#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int i,cases,caseCounter,a,b,multi =1,temp1,temp2,digits=0,revDigits;
    //cin >> cases;

    cin >> a >> b;
    temp1 = a;
    temp2 = b;
    while(temp1 != 0){
        multi *=10;
        temp1 = temp1 / 10;
        digits++;
    }
    temp1 = a;
    multi /= 10;
    revDigits = digits-1;
    int d1[digits],d2[digits];
    while(revDigits>=0){
        d1[revDigits] = temp1%10;
        temp1 = temp1/10;
        d2[revDigits] = temp2%10;
        temp2 = temp2/10;
        cout << d1[revDigits] <<endl;
        cout << d2[revDigits] <<endl;
        revDigits--;
    }








	return 0;
}
