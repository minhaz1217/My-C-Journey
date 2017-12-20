#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int tc;
    double n,sum = 1,i;
    scanf("%d", &tc);
    while(tc--){
        cin >> n;
        sum =1;
        if(n<=14){
            for(i=1;i<=n;i++){
                sum *= i;
            }
            cout << fixed << setprecision(10) << 1.00/sum << endl;
        }else{
            cout << 0.0000000000<<endl;
        }
    }

	return 0;
}
