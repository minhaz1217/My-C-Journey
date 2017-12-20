#include<iostream>
using namespace std;
int main(){
    int a,b,sum=0,flag=1;
    cin >> a;
    cin >> b;
    for(int i=a;i<=b;i++){
        if(i%2 != 0){
            if(flag == 1){
                flag = 0;
                sum += i;
            }else if(flag == 0){
                flag = 1;
                sum -= i;
            }
        }
    }
    cout << sum << endl;


    return 0;
}
