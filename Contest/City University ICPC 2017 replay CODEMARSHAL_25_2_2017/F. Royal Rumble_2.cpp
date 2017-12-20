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
        cout << fixed << setprecision(10) << 1.00/n << endl;
    }

	return 0;
}
