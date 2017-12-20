#include<bits/stdc++.h>
using namespace std;
int main(){
    long int n,m,tc,caseCounter = 1,counter,mod,big;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        if(n == 1 || m == 1){
            big = n >= m ? n : m;
            counter = big;
            cout << "Case " << caseCounter++ << ": " << counter << endl;
        }else if(n == 2 || m == 2){
            big = n >= m ? n : m;
            mod = big%4;
            if(big<=4){
                counter = 4;
            }else if(mod == 1 || mod == 3){
                counter = big+1;
            }else if(mod == 2){
                counter = big+2;
            }else{
                counter = big;
            }
            cout << "Case " << caseCounter++ << ": " << counter << endl;
        }else{
            if(n*m % 2 == 0){
                counter = n*m /2;
            }else{
                counter = (n*m + 1)/2;
            }
            cout << "Case " << caseCounter++ << ": " << counter << endl;
        }
    }
    return 0;
}
