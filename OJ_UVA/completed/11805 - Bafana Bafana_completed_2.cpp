#include<iostream>
using namespace std;
int main(){
    int a, i,j,n,k,p,arrCounter = 0,currPlayer = 0;
    cin >> a;
    int arr[a];
    for(i=0;i<a;i++){
        arr[i] = 0;
    }
    for(i=1;i<=a;i++){
        cin >> n>> k>> p;
        currPlayer = k;
        for(j=1;j<=p;j++){
            currPlayer++;
            if(currPlayer > n){
                currPlayer = 1;
            }
        }
        arr[arrCounter] = currPlayer;
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        cout << "Case " << i+1 << ": " << arr[i]<< endl;
    }


    return 0;
}
