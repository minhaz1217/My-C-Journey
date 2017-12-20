#include<iostream>
using namespace std;
int main(){
    int i,n,m,counter = 0;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        if(m%i == 0 && m/i <= n){
            counter++;
        }
    }
    cout << counter << endl;

    return 0;
}
