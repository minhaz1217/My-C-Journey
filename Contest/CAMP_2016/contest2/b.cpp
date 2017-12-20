#include<bits/stdc++.h>
using namespace std;

const int arrSize = 500;
int arrPrime[arrSize];
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


int main()
{
    int tc,n,caseCounter = 1,test,p;
    cin >> tc;
    int i = 0,counter = 1;
    while(tc--)
    {
        cin >> n;
        i = 0;
        counter = 1;
        if(n%2 == 0 && n>0){
            while(n%2 == 0)
            {
                i++;
                counter *= 4;
                n = n/2;
            }
            cout << "Case " << caseCounter++ << ": " << counter << " " << n  << endl;
        }else if(n%2 != 0){

            for(i=0;i<=primeLimit;i++){
                test = n;
                flag = 0;
                while(test%arr[i] == 0){
                    flag = 1;
                    test = test / arr[i];
                }
                if(flag == 1){
                    break;
                }
            }


        }else if(n == 0){
            cout << "Case " << caseCounter++ << ": " << 0 << " " << 0  << endl;
        }
        /*
        if(n == 0){
            counter = 0;
        }else if(n%2 != 0 ){}
        */

    }
    return 0;
}
