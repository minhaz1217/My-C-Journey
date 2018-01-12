#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int n,i,sum = 0,flag = 0;
    for(;;){
        cin >> n;
        if(n==0){break;}
        sum = 0;
        for(i=1;i<=n/2;i++){
            if(n%i == 0){
                sum +=i;
            }
        }
        if(flag == 0){
            flag=1;
            cout << "PERFECTION OUTPUT" << endl;
        }
        if(sum == n){
            cout << setw(5) << n << "  PERFECT" << endl;
        }else if(sum <n){
            cout << setw(5) << n << "  DEFICIENT" << endl;
        }else{
            cout << setw(5) << n << "  ABUNDANT" << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;

	return 0;
}
