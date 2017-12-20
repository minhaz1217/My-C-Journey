#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int prime[10002] = {0};
void sieve(){
    int i,j;
    for(i=4;i<10002;i+=2){
        prime[i] = 1;
    }
    for(i=3;i<10002;i+=2){
        if(prime[i] == 0){
            for(j = i*i;j< 10002;j+= i+i){
                prime[j] = 1;
            }
        }
    }
}

int main(){
    int n,i,j,counter =0,sumCalc = 0,sum =0;
    int newArr[1350];
    sieve();
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        sum = 0;
        counter = 0;
        sumCalc = 0;
        //here 1 isn't considered a prime
        for(i=2;i<=n;i++){
            if(!prime[i]){
                newArr[counter++] = i;
            }
        }
        for(i=0;i<counter;i++){
            sum = 0;
            for(j=i;j<counter;j++){
                sum += newArr[j];
                if(sum > n){
                    break;
                }else if(sum == n){
                    sumCalc++;
                    break;
                }
            }
        }
        cout << sumCalc << endl;
    }
    return 0;
}
