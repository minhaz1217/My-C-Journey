#include<iostream>
using namespace std;
int main(){
    int tc, i,j,n,counter=0;
    cin >> tc;
    while(tc--){
            counter =0;
        cin >> n;
        for(i=1;i<=n/2;i++){
            for(j=1;j<=i;j++){
                if((i+j) >= (n -(i+j)) && (i+j) < n && (n-(i+j))>= i ){
                   counter++;
                }
            }
        }
        cout << counter << endl;
    }
	return 0;
}
