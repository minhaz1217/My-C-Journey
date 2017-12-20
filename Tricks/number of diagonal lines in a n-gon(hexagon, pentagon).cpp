#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int num = 6,sum=0,counter = 1,i;
    cin >> num;
    sum = (num-3)*2;
    for(i=3;i<=num;i++){
        sum += (num-3)-counter;
        counter++;
        if(num-3 -counter ==0){
            break;
        }
    }
    //or sum = (num-3) + ((num-3)*(num-2)/2);
    cout << sum;
	return 0;
}
