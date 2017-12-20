#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=20,i,temp;
    for(i=2;i*i<n;i++){
        if(n%i == 0){
            n = n - (n/i);
            cout << n << endl;
        }
        cout << "i: " << i << endl;
    }
    cout << "RES: " << n << endl;


    return 0;
}
