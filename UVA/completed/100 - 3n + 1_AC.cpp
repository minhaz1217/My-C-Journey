#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,a,b,lenCounter = 0, i,currentBig= 0,big,small;
    while(1){
        cin >> a >> b;
        if(cin.eof()){
            break;
        }
        lenCounter = 0;
        currentBig = 0;
        big = a>=b? a : b;
        small = a<=b? a:b;
        for(i=small;i<=big;i++){
            n=i;
            while(n!=1){
                if(n%2 == 0){
                    n = n/2;
                }else{
                    n = 3*n + 1;
                }
                lenCounter++;
            }
            lenCounter++;
            if(lenCounter > currentBig){
                currentBig = lenCounter;
            }
            lenCounter = 0;
        }
        cout << a << " " << b << " " << currentBig << endl;
    }
    return 0;
}

