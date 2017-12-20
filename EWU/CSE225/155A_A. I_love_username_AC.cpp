#include<bits/stdc++.h>
using namespace std;
int main(){
    long long tc,big, small, n,counter = 0;
    cin >> tc;
    cin >> n;
    small = n;
    big = n;
    tc--;
    while(tc--){
        cin >> n;
        if(n > big){
            counter++;
            big = n;
        }else if(n < small){
            counter++;
            small = n;
        }
    }
    cout << counter << endl;
}
