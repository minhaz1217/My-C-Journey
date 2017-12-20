//later
#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long int num,counter = 1;
    for(;;){
        cin >> num;
        if(num ==0){
            break;
        }
        counter = 0;
        while(num>2){
            if(num %2 == 0){
                num = num/2+1;
            }else{
                num = num/2;
            }
            counter++;
        }
        if(counter %2 == 0){
            cout << "Alice" << endl;
        }else{
            cout << "Bob" << endl;
        }
    }


	return 0;
}
