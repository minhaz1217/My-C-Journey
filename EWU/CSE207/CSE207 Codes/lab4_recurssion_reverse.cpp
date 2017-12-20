#include<bits/stdc++.h>
using namespace std;
int finalNum;
int rev(int num){
        if(num/10 == 0){
            finalNum *= 10;
            finalNum += (num%10);
            return 1;
        }else{
            finalNum *= 10;
            finalNum += (num%10);
            rev(num/10);
        }
}



int main(){
    finalNum = 0;
    rev(1234560);
    cout << finalNum;
}
