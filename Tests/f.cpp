#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int i,n,k,sum = 0,a,prev = 0;
    cin >> n >> k;
    sum=k;
    for(i=1;i<=n;i++){
        cin >> a;
        if(i<=k && a == 0){
            sum--;
        }else if(i == k){
            prev = a;
        }else if(i > k && a == prev && a!=0){
            sum++;
        }
    }
    cout << sum << endl;

	return 0;
}
