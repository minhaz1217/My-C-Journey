#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int n,rev=0,temp,i,j,flag = 0;
    for(;;){
        cin >>n;
        if(cin.eof()){
            break;
        }
        flag = 0;
        if(n!=2 && n%2 == 0){
            flag = 1;
        }else{
            for(i=3;i<=n/2;i+=2){
                if(n%i == 0){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag ==0){
            temp = n;
            rev = 0;
            while(temp!=0){
                rev = rev*10 + temp%10;
                temp = temp/10;
            }
            if(rev == n){
                cout << n << " is prime." << endl;
            }else{
                flag = 0;
                if(rev!=2 && rev%2 ==0){
                    flag = 1;
                }else{
                    for(i=3;i<=rev/2;i+=2){
                        if(rev%i == 0){
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag ==0){
                    cout << n << " is emirp." << endl;
                }else{
                    cout << n << " is prime." << endl;
                }
            }


        }else{
            cout << n << " is not prime." << endl;
        }
    }

	return 0;
}
