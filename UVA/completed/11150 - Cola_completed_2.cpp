#include<iostream>
using namespace std;
int main(){

    int num,sum=0;
    for(;;){
        cin >> num;
        if(cin.eof()){
            break;
        }
        sum=0;
        sum+=num;
        while(num >=2){
            sum += num/3;
            num = (num%3) + (num/3);
            if(num == 2){
                num++;
            }
        }
        cout << sum << endl;
    }
	return 0;
}
