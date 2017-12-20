#include<iostream>
using namespace std;
int main(){
    int a,b,sum=0;
    cin >> a;
    cin >> b;
    for(int i=a;i<=b;i++){
        if(i%2 != 0){
            sum+=i;
        }
    }
    cout << sum;


    return 0;
}
