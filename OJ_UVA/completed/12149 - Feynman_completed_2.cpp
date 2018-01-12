#include<iostream>
using namespace std;
int main(){
    int num,i,sum=0;
    for(;;){
        cin >> num;
        if(num==0){
            break;
        }
        sum = 0;
        for(i=1;i<=num;i++){
            sum += i*i;
        }
        cout << sum << endl;

    }
	return 0;
}
