#include<iostream>
using namespace std;
double power(double n, int p=2){
    double ans=1.00f;
    int i;
    for(i=1;i<=p;i++){
        ans *= n;
    }
    return ans;
}
int main(){
    cout << power(2.0) << endl;
    cout << power(2.0,3) << endl;
	return 0;
}
