#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long int i,n,increaseBy = 2, tenCounter = 0,temp=1;
    cin >> n;
    for(i=0;i<n;i++){
        if(i%2 == 0){
            temp+=1;
        }else{
            temp += increaseBy;
        }
        tenCounter++;
        if(tenCounter == 10){
            increaseBy++;
            tenCounter = 0;
        }
    }
    cout << temp << endl;


	return 0;
}
