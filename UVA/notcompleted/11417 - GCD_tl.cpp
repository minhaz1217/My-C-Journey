#include<iostream>
using namespace std;
int gcd(int a, int b){
    int i,c = a>=b ? a: b,d;
    for(i=c;i>=1;i--){
        if(b%i == 0 && a%i==0){
            d = i;
            break;
        }
    }
    return d;
}
int main(){
    int N,i,j,sum=0,arr[1000], arrCounter= 0;
    for(;;){
        cin >> N;
        if(N==0){break;}
        for(i=1;i<N;i++){
            for(j=i+1;j<=N;j++){
                sum += gcd(i,j);
            }
        }
        arr[arrCounter] = sum;
        arrCounter++;
        sum =0;
    }
    for(i=0;i<arrCounter;i++){
        cout << arr[i]<< endl;
    }

    return 0;
}
