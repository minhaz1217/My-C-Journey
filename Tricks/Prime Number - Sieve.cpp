#include<iostream>
#include<math.h>
using namespace std;
const int arrSize = 500;
int arrPrime[arrSize] = {1};
int populateWithSieve(){
    int i,j, root = sqrt(arrSize);
    for(i=0;i<arrSize;i++){
        arrPrime[i] = 1;
    }
    for(i=2;i<=root;i++){
        if(arrPrime[i] == 1){
            for(j=2;i*j<=arrSize;j++){
                arrPrime[i*j] = 0;
            }
        }
    }
}
int checkIfPrime(int n){
    int i;
    if(n<2){
        return 0;
    }
    return arrPrime[n];
}
int main(){
    int i;
    populateWithSieve();
    for(i=0;i<arrSize;i++){
        cout << i << " : " << arrPrime[i] << "  ";
        if(i%5 == 0){
            cout << endl;
        }
    }


	return 0;
}
