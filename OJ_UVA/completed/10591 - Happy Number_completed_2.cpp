#include<iostream>
using namespace std;
int main(){
    int a,rnum,num,cases= 1,temp;
    cin >> a;
    while(a--){
    cin >> rnum;
    num = rnum;
        for(;;){
            if(num>=10){
                temp = num;
                num = 0;
                while(temp!=0){
                    num += (temp%10) * (temp%10);
                    temp = temp /10;
                }
            }else{
                num = num*num;
            }
            if(num == 1 ){
                cout << "Case #" << cases++ << ": " << rnum << " is a Happy number." << endl;
                break;
            }else if(num == rnum|| num<10){
                cout << "Case #" << cases++ << ": " << rnum << " is an Unhappy number." << endl;
                break;
            }
        }
    }
	return 0;
}
